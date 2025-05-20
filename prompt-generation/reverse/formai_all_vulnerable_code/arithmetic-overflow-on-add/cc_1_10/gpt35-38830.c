//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int length, uppercase, lowercase, special_character, digit;
    int total_options, i, j;
    char password[50];

    // user input
    printf("Enter the length of password (minimum 8 characters): ");
    scanf("%d", &length);
    printf("Enter the number of uppercase characters you want: ");
    scanf("%d", &uppercase);
    printf("Enter the number of lowercase characters you want: ");
    scanf("%d", &lowercase);
    printf("Enter the number of special characters you want: ");
    scanf("%d", &special_character);
    printf("Enter the number of digits you want: ");
    scanf("%d", &digit);

    // calculate total options
    total_options = uppercase + lowercase + special_character + digit;

    // check if length of password is valid or not
    if(length < 8) {
        printf("Length of password should be minimum 8 characters.\n");
        exit(0);
    }

    // check if total options are valid or not
    if(total_options > length) {
        printf("Total number of options should be less than or equal to the length of password.\n");
        exit(0);
    }

    srand(time(NULL)); // seeding the random function

    // generating random uppercase characters
    for(i=0; i<uppercase; i++) {
        password[i] = rand()%26 + 65;
    }

    // generating random lowercase characters
    for(j=i; j<i+lowercase; j++) {
        password[j] = rand()%26 + 97;
    }

    // generating random special characters
    for(i=j; i<j+special_character; i++) {
        password[i] = rand()%15 + 33;
    }

    // generating random digits
    for(j=i; j<length; j++) {
        password[j] = rand()%10 + 48;
    }

    // shuffling the password characters
    for(i=0; i<length; i++) {
        int random = rand()%length;
        char temp = password[i];
        password[i] = password[random];
        password[random] = temp;
    }

    // printing the password
    printf("Generated password: %s\n", password);

    return 0;
}