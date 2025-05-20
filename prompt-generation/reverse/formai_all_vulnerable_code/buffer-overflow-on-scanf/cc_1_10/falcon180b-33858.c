//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void playgame();
void displaymenu();
void getinput(char *input);
void checkinput(char *input);

int main() {
    srand(time(0));
    playgame();
    return 0;
}

void playgame() {
    int choice;
    char input[100];
    int health = 100;
    int score = 0;
    int level = 1;

    while(health > 0) {
        displaymenu();
        getinput(input);
        checkinput(input);
        if(strcmp(input, "attack") == 0) {
            health -= 10;
            score += 10;
        }
        else if(strcmp(input, "defend") == 0) {
            health += 5;
            score += 5;
        }
        else if(strcmp(input, "rest") == 0) {
            health += 20;
            score -= 5;
        }
        else if(strcmp(input, "quit") == 0) {
            break;
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
        system("clear");
        printf("Score: %d\n", score);
        printf("Health: %d\n", health);
    }
    if(health <= 0) {
        printf("Game Over!\n");
    }
    else {
        printf("Congratulations! You win!\n");
    }
}

void displaymenu() {
    printf("1. Attack\n");
    printf("2. Defend\n");
    printf("3. Rest\n");
    printf("4. Quit\n");
}

void getinput(char *input) {
    printf("Enter your choice: ");
    scanf("%s", input);
}

void checkinput(char *input) {
    if(strcmp(input, "attack") == 0 || strcmp(input, "defend") == 0 || strcmp(input, "rest") == 0 || strcmp(input, "quit") == 0) {
        return;
    }
    else {
        printf("Invalid input. Please try again.\n");
        getinput(input);
        checkinput(input);
    }
}