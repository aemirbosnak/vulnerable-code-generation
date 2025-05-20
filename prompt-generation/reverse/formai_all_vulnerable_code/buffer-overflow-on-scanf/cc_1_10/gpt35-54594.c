//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to store fitness information
typedef struct {
    char name[30];
    int age;
    float weight;
    float height;
    float bmi;
} FitnessInfo;

// BMI calculation function
void calculateBMI(FitnessInfo *info) {
    info->bmi = info->weight / ((info->height / 100) * (info->height / 100));
}

// Function to display fitness info
void display(FitnessInfo info) {
    printf("Name: %s\n", info.name);
    printf("Age: %d\n", info.age);
    printf("Weight: %.2f kgs\n", info.weight);
    printf("Height: %.2f cms\n", info.height);
    printf("BMI: %.2f\n", info.bmi);
}

int main() {
    int n;
    printf("Enter the number of persons: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    FitnessInfo *info = (FitnessInfo *)malloc(n * sizeof(FitnessInfo));

    // Information input
    for(int i=0;i<n;i++) {
        printf("Enter the name of person %d: ", i+1);
        scanf(" %[^\n]s", info[i].name);
        printf("Enter the age of person %d: ", i+1);
        scanf("%d", &info[i].age);
        printf("Enter the weight of person %d in kgs: ", i+1);
        scanf("%f", &info[i].weight);
        printf("Enter the height of person %d in cms: ", i+1);
        scanf("%f", &info[i].height);

        // BMI calculation
        calculateBMI(&info[i]);
    }

    // Information display
    for(int i=0;i<n;i++) {
        printf("Fitness Information of Person %d\n", i+1);
        display(info[i]);
        printf("\n");
    }

    // Freeing memory
    free(info);

    return 0;
}