//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: satisfied
#include<stdio.h>
#include<string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 30
#define MAX_NUMBER_LEN 15

struct entry {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
};

int main() {
    FILE *fp;
    fp = fopen("phonebook.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    struct entry entries[MAX_ENTRIES];
    int count = 0;
    while (fscanf(fp, "%s %s\n", entries[count].name, entries[count].number)!= EOF) {
        count++;
    }
    fclose(fp);
    printf("Phonebook:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %s\n", entries[i].name, entries[i].number);
    }
    int choice;
    do {
        printf("\nEnter your choice:\n1. Add a new entry\n2. Search for an entry\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the name (max %d characters): ", MAX_NAME_LEN - 1);
            scanf("%s", entries[count].name);
            printf("Enter the phone number (max %d characters): ", MAX_NUMBER_LEN - 1);
            scanf("%s", entries[count].number);
            count++;
            fp = fopen("phonebook.txt", "w");
            for (int i = 0; i < count; i++) {
                fprintf(fp, "%s %s\n", entries[i].name, entries[i].number);
            }
            fclose(fp);
            printf("Entry added successfully.\n");
            break;
        case 2:
            printf("Enter the name to search for: ");
            scanf("%s", entries[0].name);
            fp = fopen("phonebook.txt", "r");
            while (fscanf(fp, "%s %s\n", entries[0].name, entries[0].number)!= EOF) {
                if (strcmp(entries[0].name, entries[0].name) == 0) {
                    printf("%s %s\n", entries[0].name, entries[0].number);
                    break;
                }
            }
            fclose(fp);
            break;
        case 3:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);
    return 0;
}