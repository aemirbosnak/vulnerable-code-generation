//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//struct to store user information
typedef struct {
    char name[50];
    int age;
    int weight;
    int height;
}user;

//function to get user input
void getUserInfo(user* u) {
    printf("Enter your name: ");
    scanf("%s",u->name);

    printf("Enter your age: ");
    scanf("%d",&u->age);

    printf("Enter your weight: ");
    scanf("%d",&u->weight);

    printf("Enter your height: ");
    scanf("%d",&u->height);
}

//function to calculate BMI
float calculateBMI(float weight, float height) {
    float bmi = weight/(height*height);
    return bmi;
}

//function to print user information and BMI
void printUserInfo(user u) {
    printf("\nName: %s\n",u.name);
    printf("Age: %d\n",u.age);
    printf("Weight: %d\n",u.weight);
    printf("Height: %d\n",u.height);

    float bmi = calculateBMI(u.weight,u.height);
    printf("BMI: %.2f\n",bmi);
}

//main function
int main() {
    user u;
    getUserInfo(&u);
    printUserInfo(u);

    return 0;
}