//FormAI DATASET v1.0 Category: Funny ; Style: content
#include <stdio.h>

// Define a struct to hold a person's information
struct person {
    char name[50];
    int age;
    float height;
};

int main() {
    // Declare an array of 3 person structs
    struct person people[3];

    // Ask the user to input information for each person
    for (int i = 0; i < 3; i++) {
        printf("Enter name for person %d: ", i+1);
        scanf("%s", people[i].name);
        printf("Enter age for person %d: ", i+1);
        scanf("%d", &people[i].age);
        printf("Enter height for person %d (in meters): ", i+1);
        scanf("%f", &people[i].height);
    }

    // Output the information for each person
    for (int i = 0; i < 3; i++) {
        printf("\nPerson %d:\n", i+1);
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Height: %0.2f meters\n", people[i].height);

        // Calculate the person's BMI and output it
        float bmi = (people[i].height * people[i].height) / (float) people[i].age;
        printf("BMI: %0.2f\n", bmi);
    }

    // Find the person with the highest BMI and output their information
    int highest_bmi_index = 0;
    float highest_bmi = (people[highest_bmi_index].height * people[highest_bmi_index].height) / (float) people[highest_bmi_index].age;
    for (int i = 1; i < 3; i++) {
        float bmi = (people[i].height * people[i].height) / (float) people[i].age;
        if (bmi > highest_bmi) {
            highest_bmi_index = i;
            highest_bmi = bmi;
        }
    }
    printf("\nThe person with the highest BMI is:\n");
    printf("Name: %s\n", people[highest_bmi_index].name);
    printf("Age: %d\n", people[highest_bmi_index].age);
    printf("Height: %0.2f meters\n", people[highest_bmi_index].height);
    printf("BMI: %0.2f\n", highest_bmi);

    return 0;
}