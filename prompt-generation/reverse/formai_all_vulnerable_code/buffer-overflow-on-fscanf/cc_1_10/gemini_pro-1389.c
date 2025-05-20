//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to store a single person's information
typedef struct {
    char *name;
    int age;
    char *gender;
    char *occupation;
    char *interests;
} person_t;

// A struct to store a collection of people
typedef struct {
    person_t *people;
    int num_people;
} people_t;

// Read a collection of people from a file
people_t *read_people(char *filename) {
    FILE *fp;
    people_t *people;
    int i;

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Allocate memory for the people struct
    people = malloc(sizeof(people_t));
    if (people == NULL) {
        perror("Error allocating memory for people struct");
        fclose(fp);
        return NULL;
    }

    // Read the number of people from the file
    fscanf(fp, "%d", &people->num_people);

    // Allocate memory for the people array
    people->people = malloc(sizeof(person_t) * people->num_people);
    if (people->people == NULL) {
        perror("Error allocating memory for people array");
        fclose(fp);
        free(people);
        return NULL;
    }

    // Read the information for each person from the file
    for (i = 0; i < people->num_people; i++) {
        fscanf(fp, "%s %d %s %s %s", 
            people->people[i].name, 
            &people->people[i].age, 
            people->people[i].gender, 
            people->people[i].occupation, 
            people->people[i].interests);
    }

    // Close the file
    fclose(fp);

    // Return the people struct
    return people;
}

// Free the memory allocated for a collection of people
void free_people(people_t *people) {
    int i;

    // Free the memory allocated for each person
    for (i = 0; i < people->num_people; i++) {
        free(people->people[i].name);
        free(people->people[i].gender);
        free(people->people[i].occupation);
        free(people->people[i].interests);
    }

    // Free the memory allocated for the people array
    free(people->people);

    // Free the memory allocated for the people struct
    free(people);
}

// Print the information for a collection of people
void print_people(people_t *people) {
    int i;

    // Print the information for each person
    for (i = 0; i < people->num_people; i++) {
        printf("%s (%d) is a %s %s who is interested in %s.\n", 
            people->people[i].name, 
            people->people[i].age, 
            people->people[i].gender, 
            people->people[i].occupation, 
            people->people[i].interests);
    }
}

// Find the most compatible couple in a collection of people
person_t *find_compatible_couple(people_t *people) {
    int i, j;
    int max_compatibility = 0;
    person_t *couple = NULL;

    // Iterate over all pairs of people
    for (i = 0; i < people->num_people; i++) {
        for (j = i + 1; j < people->num_people; j++) {
            // Calculate the compatibility of the pair
            int compatibility = calculate_compatibility(people->people[i], people->people[j]);

            // If the compatibility is higher than the maximum compatibility, update the maximum compatibility and the couple
            if (compatibility > max_compatibility) {
                max_compatibility = compatibility;
                couple = malloc(sizeof(person_t) * 2);
                couple[0] = people->people[i];
                couple[1] = people->people[j];
            }
        }
    }

    // Return the most compatible couple
    return couple;
}

// Calculate the compatibility of two people
int calculate_compatibility(person_t person1, person_t person2) {
    int compatibility = 0;

    // Add 10 points for each year of age difference
    compatibility += abs(person1.age - person2.age) * 10;

    // Add 20 points if the genders are different
    if (strcmp(person1.gender, person2.gender) != 0) {
        compatibility += 20;
    }

    // Add 10 points for each occupation that is the same
    if (strcmp(person1.occupation, person2.occupation) == 0) {
        compatibility += 10;
    }

    // Add 5 points for each interest that is the same
    char *interests1 = strtok(person1.interests, ", ");
    char *interests2 = strtok(person2.interests, ", ");
    while (interests1 != NULL && interests2 != NULL) {
        if (strcmp(interests1, interests2) == 0) {
            compatibility += 5;
        }
        interests1 = strtok(NULL, ", ");
        interests2 = strtok(NULL, ", ");
    }

    // Return the compatibility
    return compatibility;
}

// Main function
int main() {
    // Read the people from the file
    people_t *people = read_people("people.txt");
    if (people == NULL) {
        return 1;
    }

    // Print the people
    print_people(people);

    // Find the most compatible couple
    person_t *couple = find_compatible_couple(people);
    if (couple == NULL) {
        printf("No compatible couples found.\n");
        return 1;
    }

    // Print the most compatible couple
    printf("The most compatible couple is %s and %s.\n", couple[0].name, couple[1].name);

    // Free the memory allocated for the people
    free_people(people);

    // Free the memory allocated for the couple
    free(couple);

    return 0;
}