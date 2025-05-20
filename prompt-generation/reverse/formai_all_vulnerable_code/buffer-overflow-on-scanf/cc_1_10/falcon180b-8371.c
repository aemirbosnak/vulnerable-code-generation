//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Defining a structure for user information
struct User{
    char name[50];
    int age;
    float height;
    float weight;
};

//Function to get user input for name
void getName(char* name){
    printf("Enter your name: ");
    scanf("%s",name);
    while(strlen(name)==0){
        printf("Name cannot be empty. Please enter your name: ");
        scanf("%s",name);
    }
}

//Function to get user input for age
int getAge(){
    int age;
    while(1){
        printf("Enter your age: ");
        scanf("%d",&age);
        if(age>=18 && age<=99){
            return age;
        }else{
            printf("Age should be between 18 and 99. Please enter your age: ");
        }
    }
}

//Function to get user input for height
float getHeight(){
    float height;
    while(1){
        printf("Enter your height in cm: ");
        scanf("%f",&height);
        if(height>=100 && height<=300){
            return height;
        }else{
            printf("Height should be between 100 and 300. Please enter your height: ");
        }
    }
}

//Function to get user input for weight
float getWeight(){
    float weight;
    while(1){
        printf("Enter your weight in kg: ");
        scanf("%f",&weight);
        if(weight>=30 && weight<=150){
            return weight;
        }else{
            printf("Weight should be between 30 and 150. Please enter your weight: ");
        }
    }
}

//Function to calculate BMI
float calculateBMI(float height, float weight){
    float bmi = weight/(height*height);
    return bmi;
}

//Function to display user information and BMI
void displayInfo(struct User user){
    printf("Name: %s\n",user.name);
    printf("Age: %d\n",user.age);
    printf("Height: %0.2f cm\n",user.height);
    printf("Weight: %0.2f kg\n",user.weight);
    printf("BMI: %0.2f\n",calculateBMI(user.height,user.weight));
}

//Main function
int main(){
    struct User user;
    getName(user.name);
    user.age = getAge();
    user.height = getHeight();
    user.weight = getWeight();
    displayInfo(user);
    return 0;
}