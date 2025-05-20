//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: excited
#include<stdio.h>

//Initializing Vote count variables as global

int candidate1 = 0, candidate2 = 0, candidate3 = 0, candidate4 = 0;

//Displaying the candidates for voting

void Display()
{
    printf("The candiates for voting are: \n\n");
    printf("1\t Rahul Kumar\n");
    printf("2\t Sanjeev Nanda\n");
    printf("3\t Maheshwar Koirala\n");
    printf("4\t Ramesh Chaudhary\n");
    printf("5\t Exit\n\n");
}

//Logic for Casting votes

void Vote(int num)
{
    if (num == 1)
        candidate1++;
    else if (num == 2)
        candidate2++;
    else if (num == 3)
        candidate3++;
    else if (num == 4)
        candidate4++;
    else
        printf("\n Invalid Vote");
}

//Calculating total number of votes

void VotesCount()
{
    printf("\n The Total Number of Votes Casted are: \n\n");
    printf("Candidate 1 - Rahul Kumar: %d\n", candidate1);
    printf("Candidate 2 - Sanjeev Nanda: %d\n", candidate2);
    printf("Candidate 3 - Maheshwar Koirala: %d\n", candidate3);
    printf("Candidate 4 - Ramesh Chaudhary: %d\n", candidate4);
}

//Declaring the main function

int main()
{
    int choice, voter;

    Display();

    //Accepting Votes

    do {
        printf("Enter your choice (5 to Exit):\t");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 4)
        {
            printf("\n Confirm your vote (1 for Yes / 0 for No):\t");
            scanf("%d", &voter);
            if (voter == 1)
                Vote(choice);
        }
        else if (choice == 5)
            break;
        else
            printf("\n Please enter a valid option.");
    } while (1);

    //Declaring the Winner

    printf("\n Result of the Election:\n");
    VotesCount();
    if (candidate1 > candidate2 && candidate1 > candidate3 && candidate1 > candidate4)
        printf("\n The Winner is Rahul Kumar!!");
    else if (candidate2 > candidate1 && candidate2 > candidate3 && candidate2 > candidate4)
        printf("\n The Winner is Sanjeev Nanda!!");
    else if (candidate3 > candidate1 && candidate3 > candidate2 && candidate3 > candidate4)
        printf("\n The Winner is Maheshwar Koirala!!");
    else if (candidate4 > candidate1 && candidate4 > candidate2 && candidate4 > candidate3)
        printf("\n The Winner is Ramesh Chaudhary!!");
    else
        printf("\n It's a TIE!!");

    return 0;
}