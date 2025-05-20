//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>

int main() {
    int num1, num2, choice;
    float result;
    
    printf("Welcome to the Arithmetic Circus!\n");
    printf("Here, numbers juggle and results flip!\n\n");
    
    // Basic menu of operations
    printf("Choose your favorite trick:\n");
    printf("1. Addition (The Great Sum-ini)\n");
    printf("2. Subtraction (The Disappearing Act)\n");
    printf("3. Multiplication (The Mighty Multiply)\n");
    printf("4. Division (The Splitting Sensation)\n");
    printf("5. Modulus (The Remainder Riders)\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);
    
    // Entering numbers
    if (choice >= 1 && choice <= 5) {
        printf("Enter the first number (the volunteer): ");
        scanf("%d", &num1);
        printf("Enter the second number (the assistant): ");
        scanf("%d", &num2);
    }
    
    // Perform the chosen operation
    switch (choice) {
        case 1:
            result = num1 + num2;
            printf("🌟 The Great Sum-ini has performed! 🎩\n");
            printf("Result: %d + %d = %.2f\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("🎭 The Disappearing Act is complete! 🎉\n");
            printf("Result: %d - %d = %.2f\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("💪 The Mighty Multiply has struck! 🚀\n");
            printf("Result: %d * %d = %.2f\n", num1, num2, result);
            break;
        case 4:
            if (num2 == 0) {
                printf("❌ Oops! The Splitting Sensation cannot divide by zero! 🎤🔥\n");
            } else {
                result = (float)num1 / num2;
                printf("📏 The Splitting Sensation has succeeded! 🙌\n");
                printf("Result: %.2f / %d = %.2f\n", (float)num1, num2, result);
            }
            break;
        case 5:
            if (num2 == 0) {
                printf("🎩 Watching the great vanish?! Cannot divide by zero! 🔮\n");
            } else {
                result = num1 % num2;
                printf("🎠 The Remainder Riders galloping away! 🐎\n");
                printf("Result: %d %% %d = %.2f\n", num1, num2, result);
            }
            break;
        default:
            printf("🤡 What kind of trick was that? I didn’t understand!\n");
            break;
    }
    
    // Final curtain call
    printf("\n🎪 Thank you for attending the Arithmetic Circus! 🎪\n");
    printf("We hope to see you again for more numerical shenanigans! 🎉\n");
    
    return 0;
}