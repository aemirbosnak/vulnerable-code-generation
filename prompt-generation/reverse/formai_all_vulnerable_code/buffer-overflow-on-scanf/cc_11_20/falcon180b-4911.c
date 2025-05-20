//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1000
#define INITIAL_VALUE 0

typedef struct {
    int id;
    char name[50];
    int size;
    int *array;
} Data;

int main() {
    int choice, size;
    char ch;
    Data *data = NULL;
    int i = 0;

    do {
        printf("\n\n");
        printf("1. Create new data\n");
        printf("2. Delete data\n");
        printf("3. Modify data\n");
        printf("4. Display data\n");
        printf("5. Exit\n");
        printf("\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the size of the data: ");
                scanf("%d", &size);
                data = (Data*)malloc(sizeof(Data));
                if(data == NULL) {
                    printf("Memory error!\n");
                    exit(0);
                }
                data->id = i++;
                data->size = size;
                data->array = (int*)malloc(sizeof(int)*size);
                if(data->array == NULL) {
                    printf("Memory error!\n");
                    exit(0);
                }
                for(int j=0; j<size; j++) {
                    data->array[j] = INITIAL_VALUE;
                }
                break;

            case 2:
                printf("Enter the id of the data to delete: ");
                scanf("%d", &data->id);
                free(data->array);
                free(data);
                data = NULL;
                break;

            case 3:
                printf("Enter the id of the data to modify: ");
                scanf("%d", &data->id);
                printf("Enter the new size of the data: ");
                scanf("%d", &size);
                data->size = size;
                data->array = (int*)realloc(data->array, sizeof(int)*size);
                if(data->array == NULL) {
                    printf("Memory error!\n");
                    exit(0);
                }
                for(int j=0; j<size; j++) {
                    data->array[j] = INITIAL_VALUE;
                }
                break;

            case 4:
                printf("The data is:\n");
                for(int j=0; j<data->size; j++) {
                    printf("%d ", data->array[j]);
                }
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }

    } while(TRUE);

    return 0;
}