//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUCKET_SIZE 10
#define MAX_ELEMENT_SIZE 50
#define ARRAY_SIZE 10

typedef struct {
    int bucket_index;
    char data[MAX_ELEMENT_SIZE];
} BucketElement;

void print_array(char arr[]) {
    printf("[");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%s", arr[i]);
        if (i != ARRAY_SIZE - 1)
            printf(", ");
    }
    printf("]\n");
}

int hash_func(char str[]) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = (hash * 31 + str[i]) % BUCKET_SIZE;
    }
    return hash;
}

void bucket_sort(char arr[]) {
    BucketElement *buckets = malloc(BUCKET_SIZE * sizeof(BucketElement));

    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i].bucket_index = i;
        strcpy(buckets[i].data, "");
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        int index = hash_func(arr[i]);
        strncat(buckets[index].data, arr[i], MAX_ELEMENT_SIZE - 1);
    }

    for (int i = 0; i < BUCKET_SIZE; i++) {
        if (strlen(buckets[i].data) > 0) {
            int j = i * (ARRAY_SIZE / BUCKET_SIZE);
            strcpy(arr[j], buckets[i].data);
        }
        memset(buckets[i].data, 0, MAX_ELEMENT_SIZE);
    }

    free(buckets);
}

int main() {
    char array[ARRAY_SIZE][MAX_ELEMENT_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%s", array[i]);
    }

    printf("Unsorted array: \n");
    print_array(array);

    bucket_sort(array);

    printf("Sorted array: \n");
    print_array(array);

    return 0;
}