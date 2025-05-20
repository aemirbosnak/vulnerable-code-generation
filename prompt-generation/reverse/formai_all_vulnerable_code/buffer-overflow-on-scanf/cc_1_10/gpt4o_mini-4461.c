//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu() {
    printf("Welcome to the Peaceful Time Travel Simulator!\n");
    printf("Choose a time period to visit:\n");
    printf("1. Ancient Greece\n");
    printf("2. The Renaissance\n");
    printf("3. The Age of Enlightenment\n");
    printf("4. The 1960s\n");
    printf("5. The Future (2050)\n");
    printf("6. Exit\n");
    printf("Enter your choice (1-6): ");
}

void travelToGreece() {
    printf("\nYou have traveled to Ancient Greece!\n");
    printf("This was a time of great cultural and intellectual achievements.\n");
    printf("Philosophers like Socrates, Plato, and Aristotle debated profound questions about life.\n");
    printf("The Olympic Games were held in honor of Zeus, bringing great joy and unity to the cities.\n");
    printf("The arts flourished with magnificent sculptures and inspiring drama.\n\n");
}

void travelToRenaissance() {
    printf("\nYou have traveled to the Renaissance!\n");
    printf("This period saw a rebirth of art, culture, and learning.\n");
    printf("The works of artists like Leonardo da Vinci and Michelangelo painted the world in vibrant colors.\n");
    printf("Humanism emerged, focusing on the potential of individuals and the beauty of nature.\n");
    printf("It was a time of exploration, where new worlds were discovered and ideas flourished.\n\n");
}

void travelToEnlightenment() {
    printf("\nYou have traveled to the Age of Enlightenment!\n");
    printf("A time when reason and science began to challenge traditions.\n");
    printf("Thinkers like Voltaire, Rousseau, and Newton inspired new ways of thinking about government, society, and nature.\n");
    printf("The idea of liberty and equality began to take root, leading to a more open-minded world.\n\n");
}

void travelTo1960s() {
    printf("\nYou have traveled to the 1960s!\n");
    printf("A decade marked by peace, love, and civil rights movements.\n");
    printf("Music, fashion, and art came together to express freedom and individuality.\n");
    printf("People gathered in harmony to promote change, with figures like Martin Luther King Jr. leading the way.\n\n");
}

void travelToFuture() {
    printf("\nYou have traveled to the Future (2050)!\n");
    printf("This future is filled with technological advancements and a greater understanding of our environment.\n");
    printf("Global collaboration has led to peace and sustainability.\n");
    printf("Humans co-exist with nature in harmony, creating innovative solutions for all.\n\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                travelToGreece();
                break;
            case 2:
                travelToRenaissance();
                break;
            case 3:
                travelToEnlightenment();
                break;
            case 4:
                travelTo1960s();
                break;
            case 5:
                travelToFuture();
                break;
            case 6:
                printf("Thank you for using the Peaceful Time Travel Simulator! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a number between 1 and 6.\n\n");
        }
    }

    return 0;
}