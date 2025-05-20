//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RELATIONSHIPS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char date[11]; // YYYY-MM-DD
    int happiness_level; // Scale from 1 to 10
} Relationship;

void add_relationship(Relationship *relationships, int *count);
void display_relationships(Relationship *relationships, int count);
void find_happiest_relationship(Relationship *relationships, int count);

int main() {
    Relationship relationships[MAX_RELATIONSHIPS];
    int count = 0;
    char choice;

    printf("Welcome to the Romantic Relationship Data Mining Tool!\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Add a relationship\n");
        printf("2. Display all relationships\n");
        printf("3. Find the happiest relationship\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_relationship(relationships, &count);
                break;
            case '2':
                display_relationships(relationships, count);
                break;
            case '3':
                find_happiest_relationship(relationships, count);
                break;
            case '4':
                printf("Thank you for using the Romantic Relationship Data Mining Tool. Until next time!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != '4');

    return 0;
}

// Function to add a relationship into the array
void add_relationship(Relationship *relationships, int *count) {
    if (*count >= MAX_RELATIONSHIPS) {
        printf("Sorry, you cannot add more relationships. Storage full.\n");
        return;
    }
    
    printf("Enter the name of your beloved: ");
    scanf("%s", relationships[*count].name);
    printf("Enter the date of the relationship (YYYY-MM-DD): ");
    scanf("%s", relationships[*count].date);
    printf("Rate your happiness level (1-10): ");
    scanf("%d", &relationships[*count].happiness_level);

    (*count)++;
    printf("Ah, a new relationship has blossomed!\n");
}

// Function to display all the relationships
void display_relationships(Relationship *relationships, int count) {
    if (count == 0) {
        printf("No relationships to display. Love is still in the air!\n");
        return;
    }

    printf("\n--- All Relationships ---\n");
    for (int i = 0; i < count; i++) {
        printf("Beloved: %s, Date: %s, Happiness Level: %d\n",
               relationships[i].name,
               relationships[i].date,
               relationships[i].happiness_level);
    }
}

// Function to find the relationship with the highest happiness level
void find_happiest_relationship(Relationship *relationships, int count) {
    if (count == 0) {
        printf("There are no relationships to evaluate. Heartbreak abounds!\n");
        return;
    }

    int happiest_index = 0;
    for (int i = 1; i < count; i++) {
        if (relationships[i].happiness_level > relationships[happiest_index].happiness_level) {
            happiest_index = i;
        }
    }

    printf("\nThe happiest relationship is with %s on %s with a happiness level of %d!\n",
           relationships[happiest_index].name,
           relationships[happiest_index].date,
           relationships[happiest_index].happiness_level);
}