//Falcon-180B DATASET v1.0 Category: File handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} Person;

int main() {
    FILE *fptr;
    Person *person;
    char ch;

    // Open the file for reading
    fptr = fopen("data.txt", "r");

    // Check if the file is opened successfully
    if (fptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read the first line of the file
    fgets(ch, sizeof(ch), fptr);

    // Create an array of people
    person = malloc(100 * sizeof(Person));

    // Read the file and store the data in the array
    int count = 0;
    while (fscanf(fptr, "%s %d\n", person[count].name, &person[count].age)!= EOF) {
        count++;
    }

    // Sort the array by age
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (person[i].age > person[j].age) {
                Person temp = person[i];
                person[i] = person[j];
                person[j] = temp;
            }
        }
    }

    // Print the sorted array
    printf("Sorted by age:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %d\n", person[i].name, person[i].age);
    }

    // Close the file
    fclose(fptr);

    // Free the memory
    free(person);

    return 0;
}