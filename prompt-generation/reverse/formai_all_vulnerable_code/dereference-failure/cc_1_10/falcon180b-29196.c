//Falcon-180B DATASET v1.0 Category: Sorting ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_STRING_LENGTH 100

typedef struct {
    char *data;
    int length;
} String;

void generateRandomString(String *str) {
    str->data = (char *) malloc(MAX_STRING_LENGTH * sizeof(char));
    str->length = rand() % MAX_STRING_LENGTH + 1;

    for (int i = 0; i < str->length; i++) {
        str->data[i] = rand() % 26 + 'a';
    }

    str->data[str->length] = '\0';
}

int compareStrings(const void *a, const void *b) {
    String *str1 = (String *) a;
    String *str2 = (String *) b;

    return strcmp(str1->data, str2->data);
}

void printArray(String arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", arr[i].data);
    }
}

int main() {
    String arr[MAX_SIZE];
    int size = 0;

    srand(time(NULL));

    while (size < MAX_SIZE) {
        String str;
        generateRandomString(&str);

        int found = 0;
        for (int i = 0; i < size; i++) {
            if (strcmp(arr[i].data, str.data) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            arr[size] = str;
            size++;
        }
    }

    qsort(arr, size, sizeof(String), compareStrings);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}