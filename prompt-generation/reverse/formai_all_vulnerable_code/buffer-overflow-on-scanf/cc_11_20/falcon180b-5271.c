//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int value;
} record_t;

int main() {
    int num_records, i, j, choice;
    record_t *records = NULL;

    printf("Enter the number of records to be stored: ");
    scanf("%d", &num_records);

    records = (record_t *)malloc(num_records * sizeof(record_t));

    for (i = 0; i < num_records; i++) {
        printf("Enter the name of the record %d: ", i+1);
        scanf("%s", records[i].name);
        printf("Enter the value of the record %d: ", i+1);
        scanf("%d", &records[i].value);
    }

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Search by Name\n");
        printf("2. Search by Value\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name to search for: ");
                char *name = (char *)malloc(strlen(records[0].name) * sizeof(char));
                scanf("%s", name);
                int found = 0;
                for (i = 0; i < num_records; i++) {
                    if (strcmp(records[i].name, name) == 0) {
                        printf("Record %d: %s (%d)\n", i+1, records[i].name, records[i].value);
                        found = 1;
                    }
                }
                if (found == 0) {
                    printf("Record not found.\n");
                }
                free(name);
                break;
            case 2:
                printf("Enter the value to search for: ");
                int value;
                scanf("%d", &value);
                int count = 0;
                for (i = 0; i < num_records; i++) {
                    if (records[i].value == value) {
                        printf("Record %d: %s (%d)\n", i+1, records[i].name, records[i].value);
                        count++;
                    }
                }
                if (count == 0) {
                    printf("Record not found.\n");
                }
                break;
            case 3:
                free(records);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}