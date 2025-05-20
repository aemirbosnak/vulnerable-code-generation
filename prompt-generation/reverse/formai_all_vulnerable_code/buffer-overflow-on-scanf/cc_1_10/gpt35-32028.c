//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int passwordLength, numChar;
    char password[50];

    srand(time(NULL)); //seed for rand function

    //display surrealistic prompt asking for password length
    printf("You have stumbled into the realm of the password genie.\n");
    printf("Enter the length of the password you desire, oh mortal.\n");
  
    //user inputs desired password length
    scanf("%d", &passwordLength);

    //while loop runs until password of desired length is generated
    while(1) 
    {
        //loop generating the password
        for (int i = 0; i < passwordLength; i++) 
        {
            //determine if lowercase, uppercase letter, or number
            numChar = rand() % 3;

            if (numChar == 0) {
                password[i] = rand() % (122-97) + 97; //lowercase letter
            }
            else if (numChar == 1) {
                password[i] = rand() % (90-65) + 65; //uppercase letter
            }
            else {
                password[i] = rand() % 10 + 48; //number
            }

        }
      
        //display surrealistic password prompt
        printf("Behold, the password genie has granted your wish! Your new password is:\n");

        //print the password
        printf("%s\n", password);

        //ask if the user is satisfied with the password
        printf("Are you satisfied with your new password, oh mortal? (Y/N)\n");

        //user inputs their answer
        char answer = getchar();

        //check if the user wants a new password or not
        if (answer == 'Y' || answer == 'y') {
            printf("Excellent, your new password shall protect your digital identity from harm.\n");
            break; //exit the while loop
        }
        else if (answer == 'N' || answer == 'n') {
            printf("Very well, the password genie shall grant you another password.\n");
        }
        else {
            printf("I am but a machine and do not understand your language, please try again.\n");
        }

    }

    printf("Thank you for using the password genie's services. Your journey continues in the digital realm.\n");

    return 0;
}