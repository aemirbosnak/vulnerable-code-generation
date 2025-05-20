//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 50

struct fortune {
    char text[100];
    char author[50];
};

void generate_fortune(struct fortune *fortune) {
    char *nouns[10] = {"love", "success", "money", "happiness", "health", "friendship", "wisdom", "adventure", "peace", "creativity"};
    char *adjectives[10] = {"great", "amazing", "wonderful", "incredible", "awesome", "fantastic", "outstanding", "remarkable", "phenomenal", "exceptional"};
    char *verbs[10] = {"will come", "awaits", "is in", "is just around the corner", "is on the horizon", "is on its way", "is about to happen", "is near", "is on the cards", "is in store"};
    char *authors[10] = {"Confucius", "Einstein", "Gandhi", "Mother Teresa", "Buddha", "Dalai Lama", "Walt Disney", "Oprah Winfrey", "Steve Jobs", "J.K. Rowling"};
    char *noun = nouns[rand() % 10];
    char *adjective = adjectives[rand() % 10];
    char *verb = verbs[rand() % 10];
    char *author = authors[rand() % 10];
    
    sprintf(fortune->text, "Your future holds %s %s %s, as foretold by %s.", adjective, noun, verb, author);
}

void print_fortune(struct fortune *fortune) {
    printf("Your fortune:\n%s\n\n", fortune->text);
}

int main() {
    srand(time(NULL));
    struct fortune fortune;
    int choice;
    
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I will generate a unique fortune for you.\n");
    printf("Press any key to begin...\n");
    getchar();
    
    generate_fortune(&fortune);
    print_fortune(&fortune);
    
    printf("Would you like another fortune? (y/n)\n");
    scanf("%c", &choice);
    
    while (choice == 'y' || choice == 'Y') {
        generate_fortune(&fortune);
        print_fortune(&fortune);
        
        printf("Would you like another fortune? (y/n)\n");
        scanf("%c", &choice);
    }
    
    printf("Thank you for using the Automated Fortune Teller!\n");
    return 0;
}