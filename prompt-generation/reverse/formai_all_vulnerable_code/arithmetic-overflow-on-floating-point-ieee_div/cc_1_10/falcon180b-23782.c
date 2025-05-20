//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 100
#define MIN 0

typedef struct{
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
    float heart_rate;
}Person;

void input(Person *p){
    printf("Enter name: ");
    scanf("%s", p->name);
    printf("Enter age: ");
    scanf("%d", &p->age);
    printf("Enter weight: ");
    scanf("%f", &p->weight);
    printf("Enter height: ");
    scanf("%f", &p->height);
    printf("Enter heart rate: ");
    scanf("%f", &p->heart_rate);
}

void calculate_bmi(Person *p){
    p->bmi = (p->weight / (p->height * p->height)) * 703;
}

void display(Person *p){
    printf("\nName: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Weight: %0.2f\n", p->weight);
    printf("Height: %0.2f\n", p->height);
    printf("BMI: %0.2f\n", p->bmi);
    printf("Heart Rate: %0.2f\n\n", p->heart_rate);
}

void main(){
    Person p[MAX];
    int n, i;

    printf("Enter number of persons: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        input(&p[i]);
        calculate_bmi(&p[i]);
    }

    printf("Fitness Tracker\n");
    for(i=0; i<n; i++){
        display(&p[i]);
    }
}