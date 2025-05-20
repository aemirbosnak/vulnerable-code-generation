//FormAI DATASET v1.0 Category: Database Indexing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_WORD_LEN 20
#define MAX_RECORDS 100000

struct Record {
    char word[MAX_WORD_LEN];
    int index;
};

struct Index {
    char word[MAX_WORD_LEN];
    int* indices;
    int size;
};

struct Index indices[MAX_RECORDS];
int num_indices = 0;
struct Record records[MAX_RECORDS];
int num_records = 0;

void* index_thread(void* arg) {
    int start_index = *((int*)arg);
    int end_index = start_index + MAX_RECORDS/2;
    for (int i = start_index; i < end_index && i < num_records; i++) {
        int found_index = -1;
        for (int j = 0; j < num_indices; j++) {
            if (strcmp(records[i].word, indices[j].word) == 0) {
                found_index = j;
                break;
            }
        }
        if (found_index == -1) {
            strcpy(indices[num_indices].word, records[i].word);
            indices[num_indices].indices = malloc(sizeof(int) * MAX_RECORDS);
            indices[num_indices].size = 1;
            indices[num_indices].indices[0] = records[i].index;
            num_indices++;
        } else {
            indices[found_index].indices[indices[found_index].size] = records[i].index;
            indices[found_index].size++;
        }
    }
    pthread_exit(NULL);
}

int main() {
    char input_word[MAX_WORD_LEN];

    printf("Enter a word:\n");
    scanf("%s", input_word);

    FILE *file_pointer;
    file_pointer = fopen("data.txt", "r");
    if (file_pointer == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char current_word[MAX_WORD_LEN];
    int index = 0;

    while (fscanf(file_pointer, "%s", current_word) == 1) {
        if (strcmp(current_word, input_word) == 0) {
            strcpy(records[num_records].word, current_word);
            records[num_records].index = index;
            num_records++;
        }
        index++;
    }

    fclose(file_pointer);

    pthread_t thread1, thread2;
    int start1 = 0, start2 = MAX_RECORDS/2;
    int rc1 = pthread_create(&thread1, NULL, index_thread, &start1);
    int rc2 = pthread_create(&thread2, NULL, index_thread, &start2);

    if (rc1 || rc2) {
        printf("Error creating threads.\n");
        return 1;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    for (int i = 0; i < num_indices; i++) {
        printf("%s: ", indices[i].word);
        for (int j = 0; j < indices[i].size; j++) {
            printf("%d ", indices[i].indices[j]);
        }
        printf("\n");
        free(indices[i].indices);
    }

    return 0;
}