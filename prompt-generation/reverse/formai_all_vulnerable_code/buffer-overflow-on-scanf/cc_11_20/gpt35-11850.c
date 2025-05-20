//FormAI DATASET v1.0 Category: Data validation ; Style: thoughtful
#include<stdio.h>
#include<string.h>

int main(){
    char name[20], address[50], email[30];
    int age, phone;
    float salary;

    printf("Enter your name: ");
    scanf("%[^\n]%*c", name);

    printf("Enter your address: ");
    scanf("%[^\n]%*c", address);

    printf("Enter your email: ");
    scanf("%s", email);

    printf("Enter your age: ");
    scanf("%d", &age);
    while(getchar() != '\n');

    printf("Enter your phone number: ");
    scanf("%d", &phone);
    while(getchar() != '\n');

    printf("Enter your salary: ");
    scanf("%f", &salary);
    while(getchar() != '\n');

    // Data validation for name
    if((strchr(name, ' ')) == NULL){
        printf("\nInvalid name, please enter your Full name\n");
        return 0;
    }

    // Data validation for address
    if(strlen(address) < 10){
        printf("\nInvalid address, please provide a valid address\n");
        return 0;
    }

    // Data validation for email
    int count1=0, count2=0, count3=0;
    for(int i=0; i<strlen(email); i++){
        if(email[i] == '@')
            count1++;
        if(email[i] == '.')
            count2++;
        if(email[i] == ' ')
            count3++;
    }
    if(count1==1 && count2==1 && count3==0){
        printf("\nEmail address is valid\n");
    }
    else{
        printf("\nInvalid email address, please enter a valid email\n");
        return 0;
    }

    // Data validation for age
    if(age < 18 || age > 60){
        printf("\nInvalid age, please enter an age between 18 and 60\n");
        return 0;
    }

    // Data validation for phone
    if(phone < 1000000000 || phone > 9999999999){
        printf("\nInvalid phone number, please enter a 10-digit phone number\n");
        return 0;
    }

    // Data validation for salary
    if(salary < 25000 || salary > 1000000){
        printf("\nInvalid salary, please enter a salary between 25000 and 1000000\n");
        return 0;
    }

    printf("\nCongratulations! All your data is valid\n\n");
    printf("Name: %s\nAddress: %s\nEmail: %s\nAge: %d\nPhone: %d\nSalary: %.2f\n", name, address, email, age, phone, salary);

    return 0;
}