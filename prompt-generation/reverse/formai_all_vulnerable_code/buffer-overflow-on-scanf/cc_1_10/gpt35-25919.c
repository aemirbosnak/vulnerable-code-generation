//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function Declarations
void displayMenu();
void addPlayer();
void displayPlayers();
void startWorkout();
void printWorkoutResults();
void displayLeaderboard();
int inputValidation(int min, int max);
float calculateBMI(float weight, float height);
void clearScreen();

//Global Variables
int numOfPlayers = 0;
int workoutTime = 0;
int numOfWorkouts = 0;

//Player struct
typedef struct {
    char name[50];
    float weight;
    float height;
    float bmi;
    int numWorkouts;
}Player;

//Array of Players
Player players[50];

int main() {
    int choice;

    do {
        displayMenu();
        choice = inputValidation(1, 5);
        switch(choice) {
            case 1:
                addPlayer();
                break;
            case 2:
                displayPlayers();
                break;
            case 3:
                startWorkout();
                break;
            case 4:
                displayLeaderboard();
                break;
            case 5:
                printf("Thanks for using the C Fitness Tracker!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("C Fitness Tracker\n");
    printf("------------------\n");
    printf("1. Add Player\n");
    printf("2. Display Players\n");
    printf("3. Start Workout\n");
    printf("4. Display Leaderboard\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
}

void addPlayer() {
    clearScreen();
    printf("Enter player name: ");
    scanf("%s", players[numOfPlayers].name);
    printf("Enter player weight (in kgs): ");
    players[numOfPlayers].weight = inputValidation(30, 200);
    printf("Enter player height (in meters): ");
    players[numOfPlayers].height = inputValidation(1, 2.5);
    players[numOfPlayers].bmi = calculateBMI(players[numOfPlayers].weight, players[numOfPlayers].height);
    players[numOfPlayers].numWorkouts = 0;
    numOfPlayers++;
    printf("\nPlayer has been added successfully!\n\n");
}

void displayPlayers() {
    clearScreen();
    if (numOfPlayers == 0) {
        printf("No players found!\n\n");
        return;
    }
    printf("List of Players\n");
    printf("------------------\n");
    for (int i=0; i<numOfPlayers; i++) {
        printf("%d. %s\n", i+1, players[i].name);
    }
    printf("\n");
}

void startWorkout() {
    clearScreen();
    if (numOfPlayers == 0) {
        printf("No players found!\n\n");
        return;
    }
    printf("Enter workout time (in minutes): ");
    workoutTime = inputValidation(10, 120);
    for (int i=0; i<numOfPlayers; i++) {
        printf("%s, Enter the number of workouts completed in the given time: ", players[i].name);
        players[i].numWorkouts = inputValidation(1, 100);
        numOfWorkouts += players[i].numWorkouts;
    }
    printf("Workout Completed Successfully!\n\n");
    printWorkoutResults();
}

void printWorkoutResults() {
    printf("Workout Results\n");
    printf("------------------\n");
    printf("Total Workout Time: %d minutes\n", workoutTime);
    printf("Total Workouts Completed: %d\n", numOfWorkouts);
    printf("Workouts Completed by Each Player\n");
    for (int i=0; i<numOfPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].numWorkouts);
    }
    printf("\n");
}

void displayLeaderboard() { 
    int option;
    clearScreen(); 
    if (numOfPlayers == 0) {
        printf("No players found!\n\n");
        return;
    }
    printf("Leaderboard\n");
    printf("------------------\n");
    printf("1. Sort by Total Number of Workouts Completed\n");
    printf("2. Sort by BMI\n");
    printf("Enter your choice (1-2): ");
    option = inputValidation(1, 2);
    printf("\n");
    if (option == 1) {
        for (int i=0; i<numOfPlayers; i++) {
            for (int j=0; j<numOfPlayers-1-i; j++) {
                if (players[j].numWorkouts < players[j+1].numWorkouts) {
                    Player temp = players[j];
                    players[j] = players[j+1];
                    players[j+1] = temp;
                }
            }
        }
        printf("Leaders Board Sorted by Total Number of Workouts Completed\n");
        printf("------------------\n");
        for (int i=0; i<numOfPlayers; i++) {
            printf("%d. %s - %d workouts\n", i+1, players[i].name, players[i].numWorkouts);
        }
    }
    else {
        for (int i=0; i<numOfPlayers; i++) {
            for (int j=0; j<numOfPlayers-1-i; j++) {
                if (players[j].bmi > players[j+1].bmi) {
                    Player temp = players[j];
                    players[j] = players[j+1];
                    players[j+1] = temp;
                }
            }
        }
        printf("Leaders Board Sorted by BMI\n");
        printf("------------------\n");
        for (int i=0; i<numOfPlayers; i++) {
            printf("%d. %s - %.2f\n", i+1, players[i].name, players[i].bmi);
        }
    }
    printf("\n");
}

int inputValidation(int min, int max) {
    int input;
    while (1) {
        if (scanf("%d", &input) != 1) {
            clearScreen();
            printf("Invalid Input! Please enter a number between %d and %d.\n", min, max);
            printf("Enter the valid input: ");
            getchar();
        }
        else if (input < min || input > max) {
            clearScreen();
            printf("Invalid Input! Please enter a number between %d and %d.\n", min, max);
            printf("Enter the valid input: ");
        } 
        else {
            getchar();
            return input;   
        }
    }
}

float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

void clearScreen() {
    system("clear||cls");
}