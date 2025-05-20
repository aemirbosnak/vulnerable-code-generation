//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100
#define NUM_FORTUNES 20

typedef struct {
    char text[MAX_LEN];
    char category[MAX_LEN];
} Fortune;

Fortune fortunes[NUM_FORTUNES] = {
    { "You will have a successful day. ", "Success" },
    { "You will find love today. ", "Love" },
    { "You will receive good news. ", "Good News" },
    { "You will have a lucky day. ", "Luck" },
    { "You will have a productive day. ", "Productivity" },
    { "You will have a creative day. ", "Creativity" },
    { "You will have a peaceful day. ", "Peace" },
    { "You will have a happy day. ", "Happiness" },
    { "You will have a healthy day. ", "Health" },
    { "You will have a successful career. ", "Career" },
    { "You will have a successful business. ", "Business" },
    { "You will have a successful relationship. ", "Relationship" },
    { "You will have a successful education. ", "Education" },
    { "You will have a successful financial situation. ", "Finance" },
    { "You will have a successful travel. ", "Travel" },
    { "You will have a successful communication. ", "Communication" },
    { "You will have a successful family life. ", "Family" },
    { "You will have a successful friendship. ", "Friendship" },
    { "You will have a successful spiritual life. ", "Spirituality" },
    { "You will have a successful personal growth. ", "Personal Growth" }
};

int main() {
    srand(time(NULL));
    int choice;
    char input[MAX_LEN];
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", input);
    printf("Hello, %s! I am here to tell you your fortune.\n", input);
    printf("Please choose your category:\n");
    printf("1. Success\n2. Love\n3. Good News\n4. Luck\n5. Productivity\n6. Creativity\n7. Peace\n8. Happiness\n9. Health\n10. Career\n11. Business\n12. Relationship\n13. Education\n14. Finance\n15. Travel\n16. Communication\n17. Family\n18. Friendship\n19. Spirituality\n20. Personal Growth\n");
    scanf("%d", &choice);
    if (choice >= 1 && choice <= 20) {
        Fortune *fortune = &fortunes[choice - 1];
        printf("Your fortune is:\n%s\n", fortune->text);
        printf("Your category is: %s\n", fortune->category);
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}