//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

//Welcome Message
printf("\n\nWelcome to the Surrealist Game!\n");
printf("-------------------------------------\n\n");
printf("Instructions:\n");
printf("There are 5 mysterious doors you have to choose from.\n");
printf("Behind each door, there is a surrealistic and unique challenge to overcome.\n");
printf("Are you ready to take the challenge?\n\n");
printf("Press Enter to start the game");
getchar();
system("clear");

srand(time(NULL));
int door;

//First Door
printf("\n\nYou are now standing in front of Door 1\n");
printf("-------------------------------------\n\n");
printf("Would you like to enter? [y/n]: ");
char response = getchar();

if (response == 'y') {
    door = 1;
} else {
    printf("\n\nCome back when you are ready for the challenge!\n");
    return 0;
}

system("clear");

//Door 1 Challenge
printf("\n\nBehind Door 1, you find a room full of stairs that go up to the sky.\n");
printf("Your challenge is to climb as high as possible in 30 seconds!\n");
printf("Press Enter to start the challenge");
getchar();
system("clear");

int height = 0;
int seconds = 30;
clock_t start_time = clock();

while (clock() - start_time < seconds * CLOCKS_PER_SEC) {
    int random = rand() % 10;
    height += random;
    printf("Climbing... [%d]\n", height);
}

printf("\n\nCongratulations! You climbed up to the clouds!\n");
printf("Press Enter to move on to the next door");
getchar();

system("clear");

//Second Door
printf("\n\nYou are now standing in front of Door 2\n");
printf("-------------------------------------\n\n");
printf("Would you like to enter? [y/n]: ");
response = getchar();

if (response == 'y') {
    door = 2;
} else {
    printf("\n\nThat's too bad, you missed all the fun!\n");
    return 0;
}

system("clear");

//Door 2 Challenge
printf("\n\nBehind Door 2, you find a room full of mirrors and a key.\n");
printf("Your challenge is to find the real key that unlocks the door in 60 seconds!\n");
printf("Press Enter to start the challenge");
getchar();
system("clear");

int key = rand() % 5;

int seconds2 = 60;
clock_t start_time2 = clock();

while (clock() - start_time2 < seconds2 * CLOCKS_PER_SEC) {
    int guess;
    printf("\n\nWhich mirror do you want to look in? ");
    scanf("%d", &guess);
    if (guess == key) {
        printf("\n\nCongratulations! You found the real key!\n");
        printf("Press Enter to move on to the next door");
        getchar();
        break;
    } else {
        printf("\n\nSorry, this mirror shows your reflection only\n");
    }
}

if (clock() - start_time2 >= seconds2 * CLOCKS_PER_SEC) {
    printf("\n\nTime's up! You missed your chance to unlock the door.\n");
    return 0;
}

system("clear");

//Third Door
printf("\n\nYou are now standing in front of Door 3\n");
printf("-------------------------------------\n\n");
printf("Would you like to enter? [y/n]: ");
response = getchar();

if (response == 'y') {
    door = 3;
} else {
    printf("\n\nMaybe next time you'll be braver!\n");
    return 0;
}

system("clear");

//Door 3 Challenge
printf("\n\nBehind Door 3, you find yourself in the middle of a forest at night.\n");
printf("Your challenge is to find the Tree of Life and retrieve an apple from it.\n");
printf("Press Enter to start the challenge");
getchar();
system("clear");

int tree = rand() % 10 + 1;

for (int i = 0; i < 5; i++) {
    int guess;
    printf("\n\nWhich direction do you want to go? [1-10] ");
    scanf("%d", &guess);
    if (guess == tree) {
        printf("\n\nYou found the Tree of Life!\n");
        int apple = rand() % 5;
        if (apple == 0) {
            printf("\n\nSorry, there were no apples on the tree. Try again later.\n");
            return 0;
        } else {
            printf("\n\nCongratulations! You found a magical apple. Eat it and move on to the next door.\n");
            printf("Press Enter to continue");
            getchar();
            break;
        }
    } else if (guess < tree) {
        printf("\n\nYou sense the tree is to the right of your position.\n");
    } else {
        printf("\n\nYou sense the tree is to the left of your position.\n");
    }
}

if (clock() - start_time2 >= seconds2 * CLOCKS_PER_SEC) {
    printf("\n\nTime's up! You missed your chance to find the Tree of Life.\n");
    return 0;
}

system("clear");

//Fourth Door
printf("\n\nYou are now standing in front of Door 4\n");
printf("-------------------------------------\n\n");
printf("Would you like to enter? [y/n]: ");
response = getchar();

if (response == 'y') {
    door = 4;
} else {
    printf("\n\nYou've come so far, why stop now?\n");
    return 0;
}

system("clear");

//Door 4 Challenge
printf("\n\nBehind Door 4, you find a room full of colors and a maze.\n");
printf("Your challenge is to find the way out of the maze only using colors.\n");
printf("Press Enter to start the challenge");
getchar();
system("clear");

char maze[5][5] = {
    {'g', 'y', 'r', 'b', 'g'},
    {'y', 'g', 'r', 'b', 'y'},
    {'g', 'r', 'b', 'y', 'g'},
    {'r', 'b', 'y', 'g', 'r'},
    {'b', 'y', 'g', 'r', 'b'}
};

char solution[20] = {'g', 'r', 'y', 'b', 'y', 'g', 'r', 'b', 'g', 'r', 'y', 'b', 'y', 'g', 'r', 'b', 'y', 'g', 'r', 'b'};

for (int i = 0; i < 20; i++) {
    int row, col;
    printf("\n\nWhich color do you see? [g/y/r/b] ");
    scanf(" %c", &solution[i]);
    printf("Which row is it in? [1-5] ");
    scanf("%d", &row);
    printf("Which column is it in? [1-5] ");
    scanf("%d", &col);
    if (maze[row - 1][col - 1] != solution[i]) {
        printf("\n\nOops! You got it wrong. Try again!\n");
        return 0;
    }
}

printf("\n\nCongratulations! You solved the maze. Press Enter to move on to the final door.");
getchar();

system("clear");

//Fifth Door
printf("\n\nYou are now standing in front of Door 5\n");
printf("-------------------------------------\n\n");
printf("Would you like to enter? [y/n]: ");
response = getchar();

if (response == 'y') {
    door = 5;
} else {
    printf("\n\nYou could be the winner! Don't give up now!\n");
    return 0;
}

system("clear");

//Door 5 Challenge
printf("\n\nBehind Door 5, you find a room full of objects and a mysterious figure.\n");
printf("Your challenge is to select the object that is the key to unlocking the final door.\n");
printf("Press Enter to start the challenge");
getchar();
system("clear");

char objects[5][15] = {
    {"A Wooden Box"},
    {"A Stone"},
    {"A Book"},
    {"A Glass Jar"},
    {"A Feather"}
};

int answer = rand() % 5;

printf("\n\nThe figure speaks:\n");
printf("I will ask you a question and you must select the correct object to show me.\n");
printf("What is both finishes a race and also works after school hours? [1-5] ");

int guess;
scanf("%d", &guess);

if (guess == answer) {
    printf("\n\nCongratulations! You have solved all challenges and have earned the key to the final door.\n");
    printf("Press Enter to open the door.");
    getchar();
} else {
    printf("\n\nSorry, that is not the correct object. You have failed the challenge and the game is over.\n");
    printf("Press Enter to close the game.");
    getchar();
    return 0;
}

system("clear");

//Final Door
printf("\n\nYou have now reached the Final Door\n");
printf("-------------------------------------\n\n");
printf("Would you like to use the key and enter? [y/n]: ");
response = getchar();

if (response == 'y') {
    printf("\n\nCongratulations! You have successfully completed the game and unlocked the Final Door!\n");
} else {
    printf("\n\nSorry, you cannot enter without the key.\n");
}

return 0;
}