//FormAI DATASET v1.0 Category: Data mining ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_LENGTH 50
#define MAX_REGISTER 100

typedef struct {
    char name[MAX_DATA_LENGTH];
    char city[MAX_DATA_LENGTH];
    int age;
} Person;

Person database[MAX_REGISTER];

int compare(const void *a, const void *b) {
    Person *pa = (Person*) a;
    Person *pb = (Person*) b;
    return strcmp(pa->name, pb->name);
}

int main(void) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;
    
    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error opening file!");
        return 1;
    }
    
    while ((read = getline(&line, &len, fp)) != -1) {
        char *token;
        int j = 0;
        char *temp[MAX_DATA_LENGTH];
        token = strtok(line, ",");
        while (token != NULL) {
            temp[j] = token;
            j++;
            token = strtok(NULL, ",");
        }
        strcpy(database[i].name, temp[0]);
        strcpy(database[i].city, temp[1]);
        database[i].age = atoi(temp[2]);
        i++;
    }
    fclose(fp);
    if (line) {
        free(line);
    }
    
    int option;
    printf("Select an option:\n");
    printf("1. Sort database by name\n");
    printf("2. Search for a person\n");
    printf("3. Exit\n");
    
    do {
        printf("Option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                qsort(database, i, sizeof(Person), compare);
                printf("Database sorted by name successfully!\n");
                break;
            case 2: {
                char search[MAX_DATA_LENGTH];
                printf("Enter name to search: ");
                scanf(" %[^\n]s", search);
                for (int j = 0; j < i; j++) {
                    if (strcmp(search, database[j].name) == 0) {
                        printf("Name: %s\n", database[j].name);
                        printf("City: %s\n", database[j].city);
                        printf("Age: %d\n", database[j].age);
                        break;
                    }
                    if (j == i-1) {
                        printf("Person not found!\n");
                    }
                }
                break;
            }
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, try again.\n");
                break;    
        }
    } while(option != 3);
    
    return 0;
}