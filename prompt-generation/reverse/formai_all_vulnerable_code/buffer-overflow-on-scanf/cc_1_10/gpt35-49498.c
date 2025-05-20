//FormAI DATASET v1.0 Category: Online Examination System ; Style: modular
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//function to display the instructions of the exam
void displayInstructions()
{
    printf("\n\t\t*************Welcome to Online Examination System*************\n\n");
    printf("\t\t\t\tRULES AND INSTRUCTIONS\n\n");
    printf("\t1. The exam has 10 questions\n");
    printf("\t2. Each question carries 1 mark\n");
    printf("\t3. There is no negative marking\n");
    printf("\t4. Answer all the questions\n");
    printf("\t5. Enter your choice as a single character (a/b/c/d)\n\n");
}

//function to take the user details
void takeUserDetails(char *name, char *registrationNumber)
{
    printf("\n\t\t\tPlease enter your details\n\n");
    printf("\tName: ");
    scanf("%s", name);
    printf("\tRegistration Number: ");
    scanf("%s", registrationNumber);
}

//function to display the menu
void displayMenu()
{
    printf("\n\n\t\t\t\tMENU\n\n");
    printf("\t1. Start the Exam\n");
    printf("\t2. View Instructions\n");
    printf("\t3. Exit\n");
}

//function to start the exam
void startExam()
{
    int score = 0;
    char answer[10];

    printf("\n\n\t\t\t\tEXAM\n\n");
    printf("\t\t\t\tTime: 1 hour\n\n");

    //Question 1
    printf("\tQ1. Who is the first Prime Minister of India?\n");
    printf("\ta. Jawaharlal Nehru\n");
    printf("\tb. Sardar Vallabhbhai Patel\n");
    printf("\tc. Mahatma Gandhi\n");
    printf("\td. Narendra Modi\n");
    printf("\tAnswer: ");
    scanf("%s", answer);
    if(strcmp(answer, "a") == 0)
    {
        printf("\tCorrect Answer\n");
        score++;
    }
    else
    {
        printf("\tIncorrect Answer\n");
    }

    //Question 2
    printf("\n\tQ2. In which year was India's Constitution adopted?\n");
    printf("\ta. 1949\n");
    printf("\tb. 1950\n");
    printf("\tc. 1951\n");
    printf("\td. 1952\n");
    printf("\tAnswer: ");
    scanf("%s", answer);
    if(strcmp(answer, "b") == 0)
    {
        printf("\tCorrect Answer\n");
        score++;
    }
    else
    {
        printf("\tIncorrect Answer\n");
    }

    //Question 3
    printf("\n\tQ3. Who discovered the theory of relativity?\n");
    printf("\ta. Isaac Newton\n");
    printf("\tb. Albert Einstein\n");
    printf("\tc. Galileo Galilei\n");
    printf("\td. Thomas Edison\n");
    printf("\tAnswer: ");
    scanf("%s", answer);
    if(strcmp(answer, "b") == 0)
    {
        printf("\tCorrect Answer\n");
        score++;
    }
    else
    {
        printf("\tIncorrect Answer\n");
    }

    //Question 4
    printf("\n\tQ4. Which metal is the best conductor of electricity?\n");
    printf("\ta. Gold\n");
    printf("\tb. Silver\n");
    printf("\tc. Copper\n");
    printf("\td. Aluminium\n");
    printf("\tAnswer: ");
    scanf("%s", answer);
    if(strcmp(answer, "b") == 0)
    {
        printf("\tCorrect Answer\n");
        score++;
    }
    else
    {
        printf("\tIncorrect Answer\n");
    }

    //Question 5
    printf("\n\tQ5. Who is the author of the book 'To Kill a Mockingbird'?\n");
    printf("\ta. Harper Lee\n");
    printf("\tb. J.K. Rowling\n");
    printf("\tc. Jane Austen\n");
    printf("\td. Charles Dickens\n");
    printf("\tAnswer: ");
    scanf("%s", answer);
    if(strcmp(answer, "a") == 0)
    {
        printf("\tCorrect Answer\n");
        score++;
    }
    else
    {
        printf("\tIncorrect Answer\n");
    }

    //Question 6
    printf("\n\tQ6. Which planet is known as the 'Red Planet'?\n");
    printf("\ta. Mars\n");
    printf("\tb. Venus\n");
    printf("\tc. Mercury\n");
    printf("\td. Jupiter\n");
    printf("\tAnswer: ");
    scanf("%s", answer);
    if(strcmp(answer, "a") == 0)
    {
        printf("\tCorrect Answer\n");
        score++;
    }
    else
    {
        printf("\tIncorrect Answer\n");
    }

    //Question 7
    printf("\n\tQ7. Which is the largest organ in human body?\n");
    printf("\ta. Liver\n");
    printf("\tb. Lungs\n");
    printf("\tc. Skin\n");
    printf("\td. Heart\n");
    printf("\tAnswer: ");
    scanf("%s", answer);
    if(strcmp(answer, "c") == 0)
    {
        printf("\tCorrect Answer\n");
        score++;
    }
    else
    {
        printf("\tIncorrect Answer\n");
    }

    //Question 8
    printf("\n\tQ8. Which is the smallest continent?\n");
    printf("\ta. Australia\n");
    printf("\tb. Antarctica\n");
    printf("\tc. Europe\n");
    printf("\td. Asia\n");
    printf("\tAnswer: ");
    scanf("%s", answer);
    if(strcmp(answer, "a") == 0)
    {
        printf("\tCorrect Answer\n");
        score++;
    }
    else
    {
        printf("\tIncorrect Answer\n");
    }

    //Question 9
    printf("\n\tQ9. Who invented the telephone?\n");
    printf("\ta. Alexander Graham Bell\n");
    printf("\tb. Thomas Edison\n");
    printf("\tc. Michael Faraday\n");
    printf("\td. Samuel Morse\n");
    printf("\tAnswer: ");
    scanf("%s", answer);
    if(strcmp(answer, "a") == 0)
    {
        printf("\tCorrect Answer\n");
        score++;
    }
    else
    {
        printf("\tIncorrect Answer\n");
    }

    //Question 10
    printf("\n\tQ10. Which city is known as the 'Pink City'?\n");
    printf("\ta. Jaipur\n");
    printf("\tb. Udaipur\n");
    printf("\tc. Jodhpur\n");
    printf("\td. Agra\n");
    printf("\tAnswer: ");
    scanf("%s", answer);
    if(strcmp(answer, "a") == 0)
    {
        printf("\tCorrect Answer\n");
        score++;
    }
    else
    {
        printf("\tIncorrect Answer\n");
    }

    printf("\n\n\t\t\t\tSCORECARD\n\n");
    printf("\tName: JOHN DOE\n");
    printf("\tRegistration Number: 123456\n\n");
    printf("\tScore: %d/10\n\n", score);
}

int main()
{
    int choice;
    char name[50], registrationNumber[50];

    //display instructions
    displayInstructions();

    //take user details
    takeUserDetails(name, registrationNumber);

    do
    {
        //display menu
        displayMenu();

        //take choice from user
        printf("\tEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                startExam();
                break;
            case 2:
                displayInstructions();
                break;
            case 3:
                printf("\n\tThank You for taking the exam!\n");
                exit(0);
            default:
                printf("\n\tInvalid Choice!\n");
        }
    }while(1);

    return 0;
}