//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Function to carry out a shocking arithmetic operation
int compute_shocking(int a, int b) {
    // Calculate the sum
    int sum = a + b;
    printf("🔆 Sum of %d & %d is: %d\n", a, b, sum);

    // Calculate the difference
    int diff = a - b;
    printf("🔥 Difference of %d & %d is: %d\n", a, b, diff);

    // Calculate the product
    int product = a * b;
    printf("💥 Product of %d & %d is: %d\n", a, b, product);

    // Handling division with a shock
    if (b == 0) {
        printf("❗ Division by Zero Error on %d / %d! Can't compute!\n", a, b);
    } else {
        float quotient = (float)a / (float)b;
        printf("⚡ Division of %d by %d equals: %.2f\n", a, b, quotient);
    }
    
    return sum + diff + product; // Returning a shocking result
}

// Function to perform modulo operation
int modulo_shocking(int a, int b) {
    if (b == 0) {
        printf("💔 Can't perform modulo, division by zero!\n");
        return -1;
    }
    int mod = a % b;
    printf("✨ Modulo of %d %% %d is: %d\n", a, b, mod);
    return mod;
}

// Main function 
int main() {
    int num1, num2;
    printf("💡 Enter two integers (num1 and num2): ");
    scanf("%d %d", &num1, &num2);

    // Call function to compute shocking arithmetic
    int shocking_result = compute_shocking(num1, num2);

    // Return the shocking sum of all calculations
    printf("🚀 Total shocking result from all operations: %d\n", shocking_result);

    // Performing modulo operation with a twist
    int mod_result = modulo_shocking(num1, num2);
    
    if (mod_result != -1) {
        printf("🌀 We are on a roll! Modulo operation successful\n");
    }

    // Let's try another surprising operation
    int num3;
    printf("🎉 Enter another integer to multiply by the first number: ");
    scanf("%d", &num3);
    printf("🤯 Multiplying %d by %d results in: %d\n", num1, num3, num1 * num3);

    // Array of shocking integers to perform operations on
    int numbers[5] = {num1, num2, num3, 15, 20};
    printf("📊 Array of numbers: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Calculate the sum of the array
    int array_sum = 0;
    for (int i = 0; i < 5; i++) {
        array_sum += numbers[i];
    }
    printf("🌪️ Sum of array elements: %d\n", array_sum);

    // Calculate the average
    float average = array_sum / 5.0;
    printf("⭐ Average of array elements: %.2f\n", average);
    
    // Check how many even numbers exist
    int even_count = 0;
    for (int i = 0; i < 5; i++) {
        if (numbers[i] % 2 == 0) even_count++;
    }
    printf("🎈 Shocked to find %d even numbers in the array!\n", even_count);

    // Using a crazy loop to find factorial of first number (num1)
    long long factorial = 1;
    for (int i = 1; i <= num1; i++) {
        factorial *= i;
    }
    printf("🔮 The factorial of %d is: %lld\n", num1, factorial);

    // Exiting the program
    printf("💫 Thank you for participating in this shocking arithmetic experience!\n");
    return 0;
}