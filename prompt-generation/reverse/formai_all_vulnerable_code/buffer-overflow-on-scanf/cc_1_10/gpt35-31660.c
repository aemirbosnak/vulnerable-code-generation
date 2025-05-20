//FormAI DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <string.h>

// Structure to represent a student
struct Student {
    int id;
    char name[50];
    float marks;
};

int main() {
    // Declare and initialize a database of students
    struct Student db[5];
    db[0].id = 1;
    strcpy(db[0].name, "John");
    db[0].marks = 75.0;
    db[1].id = 2;
    strcpy(db[1].name, "Sarah");
    db[1].marks = 83.5;
    db[2].id = 3;
    strcpy(db[2].name, "Bob");
    db[2].marks = 67.2;
    db[3].id = 4;
    strcpy(db[3].name, "Emily");
    db[3].marks = 91.0;
    db[4].id = 5;
    strcpy(db[4].name, "David");
    db[4].marks = 79.8;

    // Print all the students in the database
    printf("Database:\n");
    for(int i=0; i<5; i++) {
        printf("%d. %s - %.2f\n", db[i].id, db[i].name, db[i].marks);
    }

    // Search for a student by name
    char search_name[50];
    printf("\nEnter a name to search for: ");
    scanf("%s", search_name);
    int found = 0;
    for(int i=0; i<5; i++) {
        if(strcmp(db[i].name, search_name) == 0) {
            printf("Found: %d. %s - %.2f\n", db[i].id, db[i].name, db[i].marks);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("No student with name '%s' was found.\n", search_name);
    }

    // Update a student's marks
    int update_id;
    printf("\nEnter the ID of the student whose marks you want to update: ");
    scanf("%d", &update_id);
    int updated = 0;
    for(int i=0; i<5; i++) {
        if(db[i].id == update_id) {
            float new_marks;
            printf("Enter the new marks for %s (currently %.2f): ", db[i].name, db[i].marks);
            scanf("%f", &new_marks);
            db[i].marks = new_marks;
            printf("%s's marks have been updated to %.2f.\n", db[i].name, db[i].marks);
            updated = 1;
            break;
        }
    }
    if(!updated) {
        printf("No student with ID %d was found.\n", update_id);
    }

    // Print all the students in the database again
    printf("\nUpdated database:\n");
    for(int i=0; i<5; i++) {
        printf("%d. %s - %.2f\n", db[i].id, db[i].name, db[i].marks);
    }

    return 0;
}