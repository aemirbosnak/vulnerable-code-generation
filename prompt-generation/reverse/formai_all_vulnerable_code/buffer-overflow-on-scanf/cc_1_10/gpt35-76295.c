//FormAI DATASET v1.0 Category: File handling ; Style: futuristic
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[20];
    int age;
    char occupation[30];
} Person;

void printMenu() {
    printf("Welcome to the citizen database.\n");
    printf("1. Add new citizen\n");
    printf("2. Search citizen by name\n");
    printf("3. Print all citizens\n");
    printf("4. Exit Program\n");
}

int main() {
    FILE *filePtr;
    Person citizen[MAX_SIZE];
    int numCitizens = 0;
    int i = 0;
    int selection = 0;

    filePtr = fopen("citizens.txt", "a+");

    if (filePtr == NULL) {
        printf("Error: File could not be opened");
        return -1;
    }

    while (!feof(filePtr)) {
        fgets(citizen[numCitizens].name, 20, filePtr);
        fscanf(filePtr, "%d", &citizen[numCitizens].age);
        fgets(citizen[numCitizens].occupation, 30, filePtr);
        numCitizens++;
    }

    do {
        printMenu();
        scanf("%d", &selection);
        getchar();

        switch (selection) {
            case 1:
                printf("Enter name: ");
                fgets(citizen[numCitizens].name, 20, stdin);
                printf("Enter age: ");
                scanf("%d", &citizen[numCitizens].age);
                getchar();
                printf("Enter occupation: ");
                fgets(citizen[numCitizens].occupation, 30, stdin);
                fprintf(filePtr, "%s\n", citizen[numCitizens].name);
                fprintf(filePtr, "%d\n", citizen[numCitizens].age);
                fprintf(filePtr, "%s\n", citizen[numCitizens].occupation);
                numCitizens++;
                break;
            case 2:
                printf("Enter name to search: ");
                char searchName[20];
                fgets(searchName, 20, stdin);
                for (i = 0; i < numCitizens; i++) {
                    if (strcmp(citizen[i].name, searchName) == 0) {
                        printf("Name: %s", citizen[i].name);
                        printf("Age: %d", citizen[i].age);
                        printf("Occupation: %s", citizen[i].occupation);
                    }
                }
                break;
            case 3:
                printf("Citizens in Database:\n");
                for (i = 0; i < numCitizens; i++) {
                    printf("Name: %s", citizen[i].name);
                    printf("Age: %d", citizen[i].age);
                    printf("Occupation: %s", citizen[i].occupation);
                }
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Selection. Try Again.\n");
        }
    } while (selection != 4);

    fclose(filePtr);
    return 0;
}