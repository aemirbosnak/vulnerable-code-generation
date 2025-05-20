//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Struct to hold fortunes
struct fortune{
    char *text;
};

//Array of fortunes
struct fortune fortunes[] = {
    {"You will have good luck today."},
    {"A new opportunity is coming your way."},
    {"You will receive a pleasant surprise."},
    {"Your hard work will pay off soon."},
    {"Someone is thinking of you fondly."},
    {"You will find happiness in unexpected places."},
    {"Success is within your reach."},
    {"A positive change is on the horizon."},
    {"You will overcome any obstacles in your path."},
    {"Your future is bright and full of possibilities."}
};

//Function to generate a random number between 0 and n-1
int randInt(int n){
    return rand()%n;
}

//Function to print a random fortune
void printFortune(){
    int i = randInt(sizeof(fortunes)/sizeof(fortunes[0]));
    printf("%s\n", fortunes[i].text);
}

int main(){
    srand(time(NULL));
    int choice;

    while(1){
        printf("Welcome to the Automated Fortune Teller.\n");
        printf("What kind of fortune would you like?\n");
        printf("1. Love\n2. Money\n3. Health\n4. Career\n5. General\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("In matters of love, the cards reveal:\n");
                printFortune();
                break;
            case 2:
                printf("In matters of money, the cards reveal:\n");
                printFortune();
                break;
            case 3:
                printf("In matters of health, the cards reveal:\n");
                printFortune();
                break;
            case 4:
                printf("In matters of career, the cards reveal:\n");
                printFortune();
                break;
            case 5:
                printf("A general fortune for you:\n");
                printFortune();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\nWould you like another fortune? (y/n)\n");
        char answer;
        scanf(" %c", &answer);

        if(answer == 'n'){
            break;
        }
    }

    return 0;
}