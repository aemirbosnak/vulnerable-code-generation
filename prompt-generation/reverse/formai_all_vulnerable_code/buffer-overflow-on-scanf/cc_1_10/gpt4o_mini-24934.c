//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int age;
    float height;
    float weight;
    char comments[100];
} Person;

void addPerson(Person *people, int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Cannot add more people. Maximum entries reached.\n");
        return;
    }

    Person newPerson;
    printf("Enter name: ");
    scanf(" %[^\n]", newPerson.name);
    printf("Enter age: ");
    scanf("%d", &newPerson.age);
    printf("Enter height (in meters): ");
    scanf("%f", &newPerson.height);
    printf("Enter weight (in kg): ");
    scanf("%f", &newPerson.weight);
    printf("Enter comments: ");
    scanf(" %[^\n]", newPerson.comments);

    people[*count] = newPerson;
    (*count)++;

    printf("Person added successfully!\n");
}

void displayPeople(const Person *people, int count) {
    if (count == 0) {
        printf("No entries to display.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Height: %.2f m\n", people[i].height);
        printf("Weight: %.2f kg\n", people[i].weight);
        printf("Comments: %s\n\n", people[i].comments);
    }
}

void editPerson(Person *people, int count) {
    int index;
    printf("Enter the entry number to edit (1-%d): ", count);
    scanf("%d", &index);
    
    if (index < 1 || index > count) {
        printf("Invalid entry number.\n");
        return;
    }

    Person *personToEdit = &people[index - 1];

    printf("Editing Entry %d:\n", index);
    printf("Current Name: %s, Current Age: %d, Current Height: %.2f, Current Weight: %.2f, Current Comments: %s\n",
           personToEdit->name, personToEdit->age, personToEdit->height, personToEdit->weight, personToEdit->comments);
    
    printf("Enter new name (or press enter to keep current): ");
    char tempName[NAME_LENGTH];
    scanf(" %[^\n]", tempName);
    if (strlen(tempName) > 0) {
        strcpy(personToEdit->name, tempName);
    }

    printf("Enter new age (or -1 to keep current): ");
    int tempAge;
    scanf("%d", &tempAge);
    if (tempAge != -1) {
        personToEdit->age = tempAge;
    }

    printf("Enter new height (or -1 to keep current): ");
    float tempHeight;
    scanf("%f", &tempHeight);
    if (tempHeight != -1) {
        personToEdit->height = tempHeight;
    }

    printf("Enter new weight (or -1 to keep current): ");
    float tempWeight;
    scanf("%f", &tempWeight);
    if (tempWeight != -1) {
        personToEdit->weight = tempWeight;
    }

    printf("Enter new comments (or press enter to keep current): ");
    char tempComments[100];
    scanf(" %[^\n]", tempComments);
    if (strlen(tempComments) > 0) {
        strcpy(personToEdit->comments, tempComments);
    }

    printf("Entry updated successfully!\n");
}

void deletePerson(Person *people, int *count) {
    int index;
    printf("Enter the entry number to delete (1-%d): ", *count);
    scanf("%d", &index);
    
    if (index < 1 || index > *count) {
        printf("Invalid entry number.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        people[i] = people[i + 1];
    }
    
    (*count)--;
    printf("Entry deleted successfully!\n");
}

int main() {
    Person people[MAX_ENTRIES];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- Personal Records Management ---\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Edit Entry\n");
        printf("4. Delete Entry\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPerson(people, &count);
                break;
            case 2:
                displayPeople(people, count);
                break;
            case 3:
                editPerson(people, count);
                break;
            case 4:
                deletePerson(people, &count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}