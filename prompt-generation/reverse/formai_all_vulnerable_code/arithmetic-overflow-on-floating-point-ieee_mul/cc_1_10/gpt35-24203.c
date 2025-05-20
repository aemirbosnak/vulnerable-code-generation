//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Alan Touring
#include<stdio.h>
#include<string.h>

struct Fitness{
    char Name[50];
    int Age;
    float Height,Weight,BMI;
};

int main(){
    struct Fitness f;
    int choice;
    float weightChange;
    printf("Enter Name: ");
    fgets(f.Name,50,stdin);
    printf("Enter Age: ");
    scanf("%d",&f.Age);
    printf("Enter Height(m): ");
    scanf("%f",&f.Height);
    printf("Enter Weight(Kg): ");
    scanf("%f",&f.Weight);
    f.BMI = f.Weight / (f.Height * f.Height);
    printf("Your Current BMI is: %.2f\n", f.BMI);

    while(1){
        printf("\nSelect an option:\n");
        printf("1. Change Weight\n");
        printf("2. Display BMI\n");
        printf("3. Exit\n");
        printf("Option: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter Weight Change (Kg): ");
                scanf("%f",&weightChange);
                f.Weight += weightChange;
                f.BMI = f.Weight / (f.Height * f.Height);
                printf("Your Updated BMI is: %.2f\n", f.BMI);
                break;
            case 2:
                printf("Your Current BMI is: %.2f\n", f.BMI);
                break;
            case 3:
                printf("Thank you for using the Fitness Tracker!");
                return 0;
            default:
                printf("Invalid Choice, Try Again!\n");
        }
    }
    return 0;
}