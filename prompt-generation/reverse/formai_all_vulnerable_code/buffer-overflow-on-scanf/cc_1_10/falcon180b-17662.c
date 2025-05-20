//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_SIZE 100
#define MAX_STRING_SIZE 50

typedef struct {
    int data;
    char name[MAX_STRING_SIZE];
} person;

void bucket_sort(person arr[], int size) {
    int i, j, k, n = size / 10, temp[MAX_SIZE];
    person temp_person[MAX_SIZE];

    for(i=0; i<size; i++) {
        k = (arr[i].data) / n;
        temp_person[k] = arr[i];
    }

    for(i=0; i<n; i++) {
        for(j=0; j<size; j++) {
            if(temp_person[i].data == arr[j].data) {
                strcpy(arr[j].name, temp_person[i].name);
            }
        }
    }

    for(i=0; i<size; i++) {
        strcpy(temp[i], arr[i].name);
    }

    for(i=0; i<size; i++) {
        strcpy(arr[i].name, temp[i]);
    }
}

int main() {
    person arr[MAX_SIZE];
    int i, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter the name of element %d: ", i+1);
        scanf("%s", arr[i].name);
        printf("Enter the value of element %d: ", i+1);
        scanf("%d", &arr[i].data);
    }

    printf("\nBefore sorting:\n");
    for(i=0; i<n; i++) {
        printf("%s %d\n", arr[i].name, arr[i].data);
    }

    bucket_sort(arr, n);

    printf("\nAfter sorting:\n");
    for(i=0; i<n; i++) {
        printf("%s %d\n", arr[i].name, arr[i].data);
    }

    return 0;
}