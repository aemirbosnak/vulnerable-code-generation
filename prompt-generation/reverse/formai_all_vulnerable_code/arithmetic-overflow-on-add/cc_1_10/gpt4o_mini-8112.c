//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    int favorite_number;
} User;

void display_fortune(const char* fortune) {
    printf("\nYour Fortune:\n");
    printf("--------------------------------------------------\n");
    printf("%s\n", fortune);
    printf("--------------------------------------------------\n");
}

void generate_user_info(User *user) {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    fgets(user->name, MAX_NAME_LENGTH, stdin);
    user->name[strcspn(user->name, "\n")] = 0;  // Remove newline character

    printf("Please enter your age: ");
    scanf("%d", &user->age);

    printf("Please enter your favorite number: ");
    scanf("%d", &user->favorite_number);
}

const char* get_fortune(int random_index) {
    const char* fortunes[MAX_FORTUNES] = {
        "You will find great success in your career.",
        "A surprise is waiting for you around the corner.",
        "Your creativity will shine bright in coming days.",
        "Love is on the horizon; keep your heart open.",
        "A journey will change your perspective.",
        "An old friend will reconnect with you soon.",
        "Fortune favors the bold! Take that leap.",
        "Trust your instincts; they will guide you well.",
        "Patience is a virtue, but sometimes action is necessary.",
        "The universe has a plan for you, follow the signs."
    };
    return fortunes[random_index];
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    User user;
    
    generate_user_info(&user);

    int random_index = (user.age + user.favorite_number) % MAX_FORTUNES;
    const char* fortune = get_fortune(random_index);

    printf("\nHello, %s! At the age of %d, your favorite number %d leads us to:\n", 
           user.name, user.age, user.favorite_number);
    
    display_fortune(fortune);

    return 0;
}