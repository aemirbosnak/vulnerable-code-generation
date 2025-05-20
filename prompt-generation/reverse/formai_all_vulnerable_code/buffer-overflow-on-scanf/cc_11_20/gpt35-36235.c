//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char password[20];
    int length, upper_count = 0, lower_count = 0, num_count = 0, special_count = 0;	
    
    printf("Welcome to the Password Strength Checker! Please enter your password:\n");
    scanf("%s", password);
    length = strlen(password);
	
    if (length < 8) {
        printf("Your password is weak. You need at least 8 characters.\n");
        printf("Oops! Sorry, you will have to come up with a stronger password. Try again:\n");
        printf("Enter your new password:\n");
        scanf("%s", password);
        length = strlen(password);
    }
    
    for(int i = 0; i < length; i++)
    {
    	if(isupper(password[i]))
    		upper_count++;
    	
    	if(islower(password[i]))
    		lower_count++;
    		
    	if(isdigit(password[i]))
    		num_count++;
    		
    	if(!isalnum(password[i]))
    		special_count++;
    }
    
    if(upper_count < 1) {
    	printf("Your password is weak. You need at least one upper case letter.\n");
    	printf("Oops! Sorry, you will have to come up with a stronger password. Try again:\n");
        printf("Enter your new password:\n");
        scanf("%s", password);
        length = strlen(password);
	}
	
	if(lower_count < 1) {
    	printf("Your password is weak. You need at least one lower case letter.\n");
    	printf("Oops! Sorry, you will have to come up with a stronger password. Try again:\n");
        printf("Enter your new password:\n");
        scanf("%s", password);
        length = strlen(password);
	}
	
	if(num_count < 1) {
    	printf("Your password is weak. You need at least one numeric digit.\n");
    	printf("Oops! Sorry, you will have to come up with a stronger password. Try again:\n");
        printf("Enter your new password:\n");
        scanf("%s", password);
        length = strlen(password);
	}
	
	if(special_count < 1) {
    	printf("Your password is weak. You need at least one special character.\n");
    	printf("Oops! Sorry, you will have to come up with a stronger password. Try again:\n");
        printf("Enter your new password:\n");
        scanf("%s", password);
        length = strlen(password);
	}

	printf("Congratulations! Your password is now strong enough.\n");
	return 0;
}