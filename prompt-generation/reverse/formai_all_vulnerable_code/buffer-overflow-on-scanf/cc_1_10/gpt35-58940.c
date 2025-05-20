//FormAI DATASET v1.0 Category: Data mining ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define struct for person data
typedef struct{
    char name[30];
    int age;
    float weight;
    float height;
} PersonData;

int main(){
    // Define array of PersonData
    PersonData people[5];

    printf("Welcome! Please enter the data for five people.\n");
    
    // Retrieve data for each person from user
    for(int i=0; i<5; i++){
        printf("\nPerson %d\n", i+1);
        printf("Name: ");
        scanf("%s", people[i].name);
        printf("Age: ");
        scanf("%d", &people[i].age);
        printf("Weight (lbs): ");
        scanf("%f", &people[i].weight);
        printf("Height (inches): ");
        scanf("%f", &people[i].height);
    }

    // Calculate average age, weight, and height
    int totalAge = 0;
    float totalWeight = 0.0;
    float totalHeight = 0.0;

    for(int i=0; i<5; i++){
        totalAge += people[i].age;
        totalWeight += people[i].weight;
        totalHeight += people[i].height;
    }

    float averageAge = (float)totalAge/5;
    float averageWeight = totalWeight/5;
    float averageHeight = totalHeight/5;

    // Print average values to the user
    printf("\nAverage age: %.2f\n", averageAge);
    printf("Average weight: %.2f lbs\n", averageWeight);
    printf("Average height: %.2f inches\n", averageHeight);

    // Find person with highest weight
    float highestWeight = 0.0;
    int indexHighestWeight = 0;
    for(int i=0; i<5; i++){
        if(people[i].weight > highestWeight){
            highestWeight = people[i].weight;
            indexHighestWeight = i;
        }
    }

    // Print person with highest weight to the user
    printf("\nPerson with highest weight:\nName: %s\nAge: %d\nWeight: %.2f lbs\nHeight: %.2f inches\n",
    people[indexHighestWeight].name, people[indexHighestWeight].age, people[indexHighestWeight].weight, people[indexHighestWeight].height);

    return 0;
}