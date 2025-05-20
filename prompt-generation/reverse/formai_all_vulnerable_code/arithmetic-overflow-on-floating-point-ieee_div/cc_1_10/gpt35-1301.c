//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store user information
struct user {
    char name[50];
    int age;
    float height;
    float weight;
    float BMI;
    char address[100];
    char password[50];
};

// Function to get user inputs
struct user getUserInput() {
    struct user newUser;
    printf("Enter your full name: ");
    fgets(newUser.name, 50, stdin);
    printf("Enter your age: ");
    scanf("%d", &newUser.age);
    printf("Enter your height in meters: ");
    scanf("%f", &newUser.height);
    printf("Enter your weight in kgs: ");
    scanf("%f", &newUser.weight);
    getchar(); // flush the input buffer
    printf("Enter your address: ");
    fgets(newUser.address, 100, stdin);
    printf("Enter a password for your account: ");
    fgets(newUser.password, 50, stdin);
    return newUser;
}

// Function to calculate BMI
float calculateBMI(float height, float weight) {
    return weight / (height * height);
}

// Function to save the user data to a file
void saveUserDataToFile(struct user user) {
    FILE *fp;
    fp = fopen("userData.txt", "a");
    fprintf(fp, "%s,%d,%f,%f,%f,%s,%s\n", user.name, user.age, user.height, user.weight, user.BMI, user.address, user.password);
    fclose(fp);
}

// Function to check if a file exists
int fexists(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp) {
        fclose(fp);
        return 1;
    } else {
        return 0;
    }
}

// Function to print the user data from file
void printUserDataFromFile() {
    FILE *fp;
    char buff[255];
    if (fexists("userData.txt")) {
        fp = fopen("userData.txt", "r");
        while (fgets(buff, 255, (FILE*)fp)) {
            printf("%s", buff);
        }
        fclose(fp);   
    }
    else {
        printf("No user data found.\n");
    }
}

// Function to clear the data from the file
void clearUserDataFromFile() {
    FILE *fp = fopen("userData.txt", "w");
    fclose(fp);
    printf("All user data cleared!\n");
}

int main() {
    struct user currentUser;
    int menuOption;
    currentUser = getUserInput();
    currentUser.BMI = calculateBMI(currentUser.height, currentUser.weight);
    saveUserDataToFile(currentUser);
    printf("Thank you for signing up for the fitness tracker! Please select one of the following options:\n");
    printf("1. View user data\n");
    printf("2. Clear user data\n");
    printf("3. Exit\n");
    scanf("%d", &menuOption);
    switch(menuOption) {
        case 1:
            printUserDataFromFile();
            break;
        case 2:
            clearUserDataFromFile();
            break;
        case 3:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid option. Exiting...\n");
            break;
    }
    return 0;
}