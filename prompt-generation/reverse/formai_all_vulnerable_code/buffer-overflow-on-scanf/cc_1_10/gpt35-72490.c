//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// A structure to store the details of the user
struct User{
    char name[50];
    int birth_year;
};

// Function prototypes
void print_header();
void get_user_details(struct User*);
int calculate_age(int);
int generate_random_number();
void generate_fortune(struct User*);

int main(){
    // Initializing the seed for rand() function
    srand(time(NULL));
    
    // Printing the header
    print_header();
    
    // Creating a new User object and getting the user details
    struct User user;
    get_user_details(&user);
    
    // Generating the fortune for the user
    generate_fortune(&user);
    
    return 0;
}

/*
    This function prints the header of the program
*/
void print_header(){
    printf("**************************************************************\n");
    printf("*                 WELCOME TO THE FORTUNE TELLER              *\n");
    printf("**************************************************************\n\n");
}

/*
    This function gets the user details from the user
*/
void get_user_details(struct User *user){
    printf("Please enter your name: ");
    scanf("%s", user->name);
    
    printf("Please enter your birth year (YYYY): ");
    scanf("%d", &(user->birth_year));
}

/*
    This function calculates the age of the user based on the birth year
*/
int calculate_age(int birth_year){
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    int current_year = current_time->tm_year + 1900;
    
    return current_year - birth_year;
}

/*
    This function generates a random number between 1 and 10
*/
int generate_random_number(){
    return (rand() % 10) + 1;
}

/*
    This function generates the fortune for the user
*/
void generate_fortune(struct User *user){
    // Calculating the user's age
    int age = calculate_age(user->birth_year);
    
    // Generating a random number
    int number = generate_random_number();
    
    // Printing the fortune for the user
    printf("\n\n**************************************************************\n");
    printf("*                     YOUR FORTUNE FOR TODAY                 *\n");
    printf("**************************************************************\n\n");
    
    printf("Hello %s, your fortune for today is:\n\n", user->name);
    
    switch(age){
        case 0 ... 12:
            printf("You are young and full of energy. Today is a great day to enjoy the outdoors.\n");
            break;
        case 13 ... 29:
            printf("You are in the prime of your life. Time to make some bold decisions and take some risks.\n");
            break;
        case 30 ... 59:
            printf("You are wise and experienced. Today is a day to focus on your goals and work towards them.\n");
            break;
        default:
            printf("You have seen it all. Today is a day to relax and enjoy the simple things in life.\n");
            break;
    }
    
    printf("\n");
    
    if(number <= 3){
        printf("You will have a fortunate encounter today.\n");
    }
    else if(number <= 6){
        printf("You will receive some unexpected news today.\n");
    }
    else{
        printf("You will have a pleasant surprise today.\n");
    }
    
    printf("\n");
    printf("**************************************************************\n\n");
}