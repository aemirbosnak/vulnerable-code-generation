//FormAI DATASET v1.0 Category: Data validation ; Style: inquisitive
#include<stdio.h> 

int main() 
{ 
    int age; 
    printf("What is your age? "); 
    scanf("%d",&age); 

    //If age is less than 18, ask for confirmation from parent/guardian. 
    if (age < 18) 
    { 
        char confirmation; 
        printf("You are below 18 years old. Do you have parental/guardian permission? (Y/N) "); 
        scanf(" %c",&confirmation); 

        //If confirmation is yes, proceed with the program. 
        if(confirmation == 'Y' || confirmation == 'y') 
        { 
            printf("Thank you! You may continue.\n"); 
        } 
        //If confirmation is no, terminate the program. 
        else if(confirmation == 'N' || confirmation == 'n') 
        { 
            printf("Sorry, you need parental/guardian permission to continue.\n"); 
            return 0; 
        } 
        //If confirmation is not Y or N, ask again. 
        else 
        { 
            printf("Invalid input. Please enter Y or N.\n"); 
            scanf(" %c",&confirmation); 
        } 
    } 

    //If age is greater than or equal to 18, proceed with the program. 
    else 
    { 
        printf("Thank you! You may continue.\n"); 
    } 

    //Ask for a phone number. Must be in the format XXX-XXX-XXXX. 
    char phone_number[12]; 
    printf("What is your phone number? (Format: XXX-XXX-XXXX) "); 
    scanf("%11s", phone_number); 

    //Check that phone number fits the format of XXX-XXX-XXXX 
    int i; 
    for(i = 0; i < 12; i++) 
    { 
        if(i == 3 || i == 7) 
        { 
            if(phone_number[i] != '-') 
            { 
                printf("Invalid phone number format. Please enter in format XXX-XXX-XXXX.\n"); 
                return 0; 
            } 
        } 
        else 
        { 
            if(phone_number[i] < '0' || phone_number[i] > '9') 
            { 
                printf("Invalid phone number format. Please enter in format XXX-XXX-XXXX.\n"); 
                return 0; 
            } 
        } 
    } 

    printf("Thank you! Your phone number is %s.\n", phone_number); 
    return 0; 
}