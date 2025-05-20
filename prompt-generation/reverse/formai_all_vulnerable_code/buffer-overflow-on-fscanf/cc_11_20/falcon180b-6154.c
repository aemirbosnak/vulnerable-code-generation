//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Entry;

int main() {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (fscanf(fp, "%s %s", entries[num_entries].name, entries[num_entries].value) == 2) {
        num_entries++;
        if (num_entries == MAX_ENTRIES) {
            printf("Maximum number of entries reached\n");
            break;
        }
    }

    fclose(fp);

    int choice;
    while (1) {
        printf("Fitness Tracker\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name (max %d characters): ", MAX_NAME_LEN - 1);
            scanf("%s", entries[num_entries].name);

            printf("Enter value (max %d characters): ", MAX_VALUE_LEN - 1);
            scanf("%s", entries[num_entries].value);

            fp = fopen("data.txt", "a");
            if (fp == NULL) {
                printf("Error opening file\n");
                break;
            }

            fprintf(fp, "%s %s\n", entries[num_entries].name, entries[num_entries].value);
            fclose(fp);

            num_entries++;
            if (num_entries == MAX_ENTRIES) {
                printf("Maximum number of entries reached\n");
            }
            break;

        case 2:
            fp = fopen("data.txt", "r");
            if (fp == NULL) {
                printf("Error opening file\n");
                break;
            }

            printf("Name\tValue\n");
            for (int i = 0; i < num_entries; i++) {
                printf("%s\t%s\n", entries[i].name, entries[i].value);
            }

            fclose(fp);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}