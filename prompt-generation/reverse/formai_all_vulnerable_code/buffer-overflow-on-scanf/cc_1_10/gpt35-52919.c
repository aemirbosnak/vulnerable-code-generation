//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>

//Define a struct to hold user information
struct user{
    int age;
    float height;
    float weight;
    char gender;
};

//Define a function to calculate the user's BMI
float calculateBMI(float height, float weight){
    float bmi = weight / (height * height);
    return bmi;
}

//Define a function to check if the user is overweight, underweight or healthy
void checkBMI(float bmi){
    if(bmi < 18.5){
        printf("You are underweight\n");
    }
    else if(bmi >= 18.5 && bmi < 25){
        printf("You are at a healthy weight\n");
    }
    else{
        printf("You are overweight\n");
    }
}

//Define a function to get user information
struct user getUserInfo(){
    struct user new_user;
    printf("Enter your age: ");
    scanf("%d", &new_user.age);
    printf("Enter your height in meters: ");
    scanf("%f", &new_user.height);
    printf("Enter your weight in kilograms: ");
    scanf("%f", &new_user.weight);
    printf("Enter your gender (M/F): ");
    scanf(" %c", &new_user.gender);
    return new_user;
}

int main(){
    int menu_choice;
    struct user current_user;
    float current_bmi;
    //Get user information
    current_user = getUserInfo();
    
    do{
        //Display options
        printf("\nChoose an option:\n");
        printf("1. View BMI\n");
        printf("2. View weight loss goal\n");
        printf("3. Change user information\n");
        printf("4. Quit\n");
        scanf("%d", &menu_choice);
        
        switch(menu_choice){
            case 1:
                //Calculate current BMI and display result
                current_bmi = calculateBMI(current_user.height, current_user.weight);
                printf("Your current BMI is %0.1f\n", current_bmi);
                //Check if user is overweight, underweight or healthy
                checkBMI(current_bmi);
                break;
            case 2:
                //Calculate weight loss goal and display result
                if(current_user.gender == 'M'){
                    printf("Your weight loss goal is %0.1f kg\n", (current_user.height * 100 - 100 - (current_user.age / 10)) * 0.9);
                }
                else{
                    printf("Your weight loss goal is %0.1f kg\n", (current_user.height * 100 - 100 - (current_user.age / 10)) * 0.85);
                }
                break;
            case 3:
                //Get updated user information
                current_user = getUserInfo();
                break;
            case 4:
                //Quit program
                printf("Thank you for using the Fitness Tracker\n");
                break;
            default:
                printf("Invalid option, please try again\n");
                break;
        }
    }while(menu_choice != 4);
    return 0;
}