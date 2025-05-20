//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main () {
    int i,result;
    char name[20], question[100];
    srand(time(NULL)); //sets the seed value for the random number generator
    
    printf("Hello, my name is Satisfied Bot and I am an automated fortune teller. What is your name?\n");
    scanf("%s", name);
    
    printf("Nice to meet you, %s. What is your question for me? Please type it below and press ENTER.\n", name);
    scanf(" %[^\n]s", question); //scanf() with %[^\n]s to accept the entire line as input
    
    printf("Hmm, let me think...\n");

    for (i = 1; i <= 10; i++) { //loop to generate random sleep duration for "thinking"
        printf(".");
        fflush(stdout); //forces output to be displayed immediately
        sleep(1); //pauses the program for 1 second
    }

    result = rand() % 10 + 1; //generates a random number between 1 and 10

    switch(result) {
        case 1:
            printf("\n%s, I see great things in your future. You will achieve all your goals and find true happiness.\n", name);
            break;
        case 2:
            printf("\n%s, be careful with your finances. You may encounter unexpected expenses in the near future.\n", name);
            break;
        case 3:
            printf("\n%s, you are surrounded by negativity. Stay away from toxic people and focus on positive thoughts.\n", name);
            break;
        case 4:
            printf("\n%s, love is on the horizon. You will soon meet someone special who will change your life.\n", name);
            break;
        case 5:
            printf("\n%s, your hard work will pay off soon. Keep pushing through and success will come.\n", name);
            break;
        case 6:
            printf("\n%s, be open to new opportunities. A big change is coming and it will lead to a better future.\n", name);
            break;
        case 7:
            printf("\n%s, your health may suffer if you don't take better care of yourself. Make time for self-care and rest.\n", name);
            break;
        case 8:
            printf("\n%s, new adventures await you. Embrace the unknown and take risks.\n", name);
            break;
        case 9:
            printf("\n%s, don't be afraid to ask for help when you need it. Supportive people are all around you.\n", name);
            break;
        case 10:
            printf("\n%s, remember to appreciate the good things in your life. Gratitude will bring more blessings.\n", name);
            break;
        default:
            printf("\nOops, something went wrong. Please ask your question again.\n");
            break;
    }
    
    printf("Thank you for using Satisfied Bot, the best automated fortune teller around. Have a great day!\n");
    
    return 0;
}