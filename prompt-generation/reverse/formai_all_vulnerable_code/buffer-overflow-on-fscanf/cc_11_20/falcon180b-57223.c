//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define DELIM ","

typedef struct {
    char name[MAX_SIZE];
    char email[MAX_SIZE];
} contact;

int main() {
    FILE* fp;
    contact* contacts = NULL;
    int count = 0;

    fp = fopen("contacts.csv", "r");
    if(fp == NULL) {
        printf("File not found\n");
        exit(1);
    }

    while(fscanf(fp, "%s,%s", contacts[count].name, contacts[count].email)!= EOF) {
        count++;
        if(count == MAX_SIZE) {
            printf("Maximum number of contacts reached\n");
            exit(1);
        }
    }

    fclose(fp);

    int choice;
    char name[MAX_SIZE];

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. View contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                fp = fopen("contacts.csv", "a");
                if(fp == NULL) {
                    printf("Error opening file\n");
                    exit(1);
                }
                fprintf(fp, "%s,%s\n", name, "");
                fclose(fp);
                printf("Contact added successfully\n");
                break;
            case 2:
                printf("Enter name to remove: ");
                scanf("%s", name);
                fp = fopen("contacts.csv", "w");
                if(fp == NULL) {
                    printf("Error opening file\n");
                    exit(1);
                }
                int i;
                for(i = 0; i < count; i++) {
                    if(strcmp(contacts[i].name, name)!= 0) {
                        fprintf(fp, "%s,%s\n", contacts[i].name, contacts[i].email);
                    }
                }
                fclose(fp);
                printf("Contact removed successfully\n");
                break;
            case 3:
                printf("Name\tEmail\n");
                for(int i = 0; i < count; i++) {
                    printf("%s\t%s\n", contacts[i].name, contacts[i].email);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice!= 4);

    return 0;
}