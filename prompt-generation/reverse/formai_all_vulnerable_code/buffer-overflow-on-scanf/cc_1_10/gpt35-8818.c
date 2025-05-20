//FormAI DATASET v1.0 Category: Data mining ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

// Define structure for storing student record
struct Student {
    char name[20];
    int age;
    float height;
    float weight;
    char gender;
};

// Function to find average height of students
float findAvgHeight(struct Student *arr, int n) {
    int i;
    float sum = 0;
    for(i=0; i<n; i++) {
        sum += arr[i].height;
    }
    return sum/n;
}

// Function to find average weight by gender
void findAvgWeightByGender(struct Student *arr, int n) {
    int i;
    float weight_sum_f = 0, weight_sum_m = 0;
    int count_f = 0, count_m = 0;

    // calculate sum of weights and count of students by gender
    for(i=0; i<n; i++) {
        if(arr[i].gender == 'F') {
            weight_sum_f += arr[i].weight;
            count_f++;
        }
        else {
            weight_sum_m += arr[i].weight;
            count_m++;
        }
    }

    // calculate and print average weights
    printf("\nAverage weight of female students: %f", weight_sum_f/count_f);
    printf("\nAverage weight of male students: %f", weight_sum_m/count_m);
}

int main() {
    struct Student students[5];
    int i;

    // Get student details
    for(i=0; i<5; i++) {
        printf("\nEnter details of student %d", i+1);
        printf("\nName: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Height (in meters): ");
        scanf("%f", &students[i].height);
        printf("Weight (in kgs): ");
        scanf("%f", &students[i].weight);
        printf("Gender (M/F): ");
        scanf(" %c", &students[i].gender);
    }

    // find and display average height of students
    float avg_height = findAvgHeight(students, 5);
    printf("\nAverage height of students: %f", avg_height);

    // find and display average weight by gender
    findAvgWeightByGender(students, 5);

    return 0;
}