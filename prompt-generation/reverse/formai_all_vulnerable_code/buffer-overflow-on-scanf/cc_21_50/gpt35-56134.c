//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() 
{
    int num;
    char ans;
    srand(time(0));  //seeding the random number generator

    printf("*** Welcome to the Automated Fortune Teller Program! ***\n\n");
    printf("Think of a question and I'll tell you the answer...\n\n");
    printf("Press enter to continue!");

    getchar();  //wait for input

    printf("\n\n");

    do {
        num = rand() % 20;  //generating a random number between 0 and 19

        printf("The answer to your question is: ");

        switch (num) {
            case 0:
                printf("Yes\n\n");
                break;
            case 1:
                printf("No\n\n");
                break;
            case 2:
                printf("Ask again later\n\n");
                break;
            case 3:
                printf("Outlook good\n\n");
                break;
            case 4:
                printf("Don't count on it\n\n");
                break;
			case 5:
				printf("Cannot predict now\n\n");
				break;
			case 6:
				printf("It is certain\n\n");
				break;
			case 7:
				printf("Very doubtful\n\n");
				break;
			case 8:
				printf("Most likely\n\n");
				break;
			case 9:
				printf("My sources say no\n\n");
				break;
			case 10:
				printf("Reply hazy, try again\n\n");
				break;
			case 11:
				printf("Better not tell you now\n\n");
				break;
			case 12:
				printf("Yes - definitely\n\n");
				break;
			case 13:
				printf("Concentrate and ask again\n\n");
				break;
			case 14:
				printf("My reply is no\n\n");
				break;
			case 15:
				printf("Signs point to yes\n\n");
				break;
			case 16:
				printf("Ask again later\n\n");
				break;
			case 17:
				printf("Don't count on it\n\n");
				break;
			case 18:
				printf("Yes, in due time\n\n");
				break;
			case 19:
				printf("My sources say no\n\n");
				break;
            default:
                printf("Oops! Something went wrong...\n\n");
                break;
        }

        printf("Do you have another question? (y/n): ");
        scanf(" %c", &ans);

        printf("\n\n");

    } while (ans == 'y' || ans == 'Y');  //continue until user types 'n' or 'N'

    printf("Thank you for using the Automated Fortune Teller Program!\n");

    return 0;
}