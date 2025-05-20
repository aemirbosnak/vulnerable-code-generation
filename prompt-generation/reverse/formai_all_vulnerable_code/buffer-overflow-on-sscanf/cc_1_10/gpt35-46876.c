//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining struct for holding user data
struct User{
    int age;
    char gender[10];
    float height;
    float weight;
    float bmi;
};

// function to calculate BMI
float calculate_bmi(float w, float h){
    return w/(h*h);
}

// function to display user data
void display_user(struct User u){
    printf("\nUser Data: \n");
    printf("Age: %d\n", u.age);
    printf("Gender: %s\n", u.gender);
    printf("Height: %.2f m\n", u.height);
    printf("Weight: %.2f kg\n", u.weight);
    printf("BMI: %.2f\n", u.bmi);
}

// function to get user data
struct User get_user_data(){
    struct User u;
    printf("Enter user details:\n");
    printf("Age: ");
    scanf("%d", &u.age);
    printf("Gender (Male or Female): ");
    scanf("%s", u.gender);
    printf("Height (in meters): ");
    scanf("%f", &u.height);
    printf("Weight (in kilograms): ");
    scanf("%f", &u.weight);
    u.bmi = calculate_bmi(u.weight, u.height);
    return u;
}

int main(){

    int menu_choice;
    struct User current_user;
    char line[100];

    // menu loop
    do{
        printf("\nWelcome to our Fitness Tracker App!\n");
        printf("1. Enter User Data\n");
        printf("2. View User Data\n");
        printf("3. Exit\n");
        printf("Enter menu choice (1-3): ");
        fgets(line, 100, stdin);
        sscanf(line, "%d", &menu_choice);

        switch(menu_choice) {
            case 1: 
                current_user = get_user_data();
                break;

            case 2:
                display_user(current_user);
                break;

            case 3:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (menu_choice != 3);
    
    return 0;
}