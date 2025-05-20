//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 50

void showInstructions() {
    printf("Welcome to the Cheerful Drone Remote Control Program!\n");
    printf("Use the following commands to control your drone:\n");
    printf(" 1. 'takeoff' - Make your drone soar into the skies!\n");
    printf(" 2. 'land' - Bring your beautiful bird home gently.\n");
    printf(" 3. 'forward <distance>' - Buzz forward a delightful distance!\n");
    printf(" 4. 'backward <distance>' - Retreat with grace!\n");
    printf(" 5. 'left <distance>' - Glide to the left like a joyfully dancing leaf!\n");
    printf(" 6. 'right <distance>' - Swim to the right, as if in a happy river!\n");
    printf(" 7. 'rotate <degrees>' - Spin around in circles of fun!\n");
    printf(" 8. 'status' - Check how your gorgeous drone is feeling!\n");
    printf(" 9. 'exit' - Wave goodbye and land your drone safely.\n");
    printf("Please enter your command below:\n");
}

void takeOff() {
    printf("🚀 Your drone is taking off and reaching for the sky! 🎉\n");
}

void land() {
    printf("🌍 Your drone is gently landing back to Earth. 🐦\n");
}

void moveForward(int distance) {
    printf("➡️ Your drone is flying forward for %d meters. Enjoy the view! 🌈\n", distance);
}

void moveBackward(int distance) {
    printf("⬅️ Your drone is gracefully moving backward %d meters. What a sight! 🌼\n", distance);
}

void moveLeft(int distance) {
    printf("⬅️ Your drone is gliding left for %d meters. Dance like nobody's watching! 🔄\n", distance);
}

void moveRight(int distance) {
    printf("➡️ Your drone is swimming right for %d meters. Feel the breeze! 🌊\n", distance);
}

void rotate(int degrees) {
    printf("🔄 Your drone is spinning around %d degrees. Wheee! 🎊\n", degrees);
}

void showStatus() {
    printf("✅ Your drone is happy and ready to fly! Let's keep adventuring!\n");
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    int distance, degrees;

    showInstructions();

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        
        // Remove the newline character from the command
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "takeoff") == 0) {
            takeOff();
        } else if (strcmp(command, "land") == 0) {
            land();
        } else if (sscanf(command, "forward %d", &distance) == 1) {
            moveForward(distance);
        } else if (sscanf(command, "backward %d", &distance) == 1) {
            moveBackward(distance);
        } else if (sscanf(command, "left %d", &distance) == 1) {
            moveLeft(distance);
        } else if (sscanf(command, "right %d", &distance) == 1) {
            moveRight(distance);
        } else if (sscanf(command, "rotate %d", &degrees) == 1) {
            rotate(degrees);
        } else if (strcmp(command, "status") == 0) {
            showStatus();
        } else if (strcmp(command, "exit") == 0) {
            printf("👋 Thank you for flying with us! Have a wonderful day! 🌞\n");
            break;
        } else {
            printf("❌ Oops! I didn't understand that command. Please try again!\n");
        }
        
        sleep(1);  // Pause to let the user enjoy the output!
    }

    return 0;
}