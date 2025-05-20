//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include<stdio.h>
#include<string.h>

struct fitness{
    char name[20];
    int age;
    float weight;
    float height;
    float bmi;
    int steps;
};

int main(){
    struct fitness user[10]; // to store data of maximum 10 users
    int user_count=0, option, i, j, flag=0, count;
    float average_bmi, total_bmi=0;

    do{
        printf("\nWelcome to Fitness Tracker!");

        printf("\n1. Add User\n");
        printf("2. Display User Details\n");
        printf("3. Update User Details\n");
        printf("4. Delete User Data\n");
        printf("5. Display User with Highest Steps\n");
        printf("6. Display Average BMI\n");
        printf("7. Exit\n");
        printf("\nEnter Option Number: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                // Add User
                if(user_count>=10){
                    printf("\nMaximum Limit Reached!");
                    break;
                }
                printf("\nEnter Name: ");
                scanf("%s", &user[user_count].name);
                printf("Enter Age: ");
                scanf("%d", &user[user_count].age);
                printf("Enter Weight in Kg: ");
                scanf("%f", &user[user_count].weight);
                printf("Enter Height in Meters: ");
                scanf("%f", &user[user_count].height);

                user[user_count].bmi=user[user_count].weight/(user[user_count].height*user[user_count].height);
                printf("BMI: %f", user[user_count].bmi);
                user_count++;
                flag=1;
                break;


            case 2:
                //Display User Details
                if(!flag){
                    printf("\nNo Data Found!");
                    break;
                }

                for(i=0;i<user_count;i++){
                    printf("\nUser %d Details:", i+1);
                    printf("\nName: %s", user[i].name);
                    printf("\nAge: %d", user[i].age);
                    printf("\nWeight: %f", user[i].weight);
                    printf("\nHeight: %f", user[i].height);
                    printf("\nBMI: %f", user[i].bmi);
                }
                break;


            case 3:
                // Update User Details
                if(!flag){
                    printf("\nNo Data Found!");
                    break;
                }

                printf("\nEnter User Number to Update: ");
                scanf("%d", &count);

                printf("\nSelect User Detail to Update:");
                printf("\n1. Name");
                printf("\n2. Age");
                printf("\n3. Weight");
                printf("\n4. Height");
                printf("\nEnter Option Number: ");
                scanf("%d", &option);

                printf("\nEnter New Value: ");

                switch(option){
                    case 1:
                        scanf("%s", &user[count-1].name);
                        break;
                    case 2:
                        scanf("%d", &user[count-1].age);
                        break;
                    case 3:
                        scanf("%f", &user[count-1].weight);
                        break;
                    case 4:
                        scanf("%f", &user[count-1].height);
                        break;
                    default:
                        printf("\nInvalid Option!");
                        break;
                }

                user[count-1].bmi=user[count-1].weight/(user[count-1].height*user[count-1].height);
                printf("BMI: %f", user[count-1].bmi);

                break;


            case 4:
                // Delete User Data
                if(!flag){
                    printf("\nNo Data Found!");
                    break;
                }

                printf("\nEnter User Number to Delete: ");
                scanf("%d", &count);

                for(i=count-1;i<user_count-1;i++){
                    strcpy(user[i].name, user[i+1].name);
                    user[i].age=user[i+1].age;
                    user[i].weight=user[i+1].weight;
                    user[i].height=user[i+1].height;
                    user[i].bmi=user[i+1].bmi;
                }
                user_count--;
                printf("\nUser Data Deleted");

                break;


            case 5:
                //Display User with Highest Steps
                if(!flag){
                    printf("\nNo Data Found!");
                    break;
                }

                printf("\nEnter Total Steps: ");
                scanf("%d", &user[0].steps); // Assuming user 1 has highest steps

                for(i=1;i<user_count;i++){
                    printf("\nEnter Total Steps for User %d: ", i+1);
                    scanf("%d", &user[i].steps);

                    if(user[i].steps>user[0].steps){
                        user[0].steps=user[i].steps; // storing highest value in user 1
                        j=i; // storing user number with highest steps
                    }
                }

                printf("\nUser with Highest Steps:");
                printf("\nName: %s", user[j].name);
                printf("\nTotal Steps: %d", user[0].steps);

                break;


            case 6:
                // Display Average BMI
                if(!flag){
                    printf("\nNo Data Found!");
                    break;
                }

                for(i=0;i<user_count;i++){
                    total_bmi+=user[i].bmi;
                }

                average_bmi=total_bmi/user_count;
                printf("\nAverage BMI of All Users: %f", average_bmi);

                break;


            case 7:
                printf("\n\nExiting Program...");
                break;


            default:
                printf("\n\nInvalid Option!");
        }

    }while(option!=7);

    return 0;
}