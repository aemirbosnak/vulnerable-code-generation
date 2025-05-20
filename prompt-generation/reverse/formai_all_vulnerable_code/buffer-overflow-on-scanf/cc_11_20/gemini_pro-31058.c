//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("Welcome to my fun math exercise program! ☀️\n");

    // Let's start with a simple addition problem:
    int num1 = 123;
    int num2 = 456;
    int sum = num1 + num2;
    printf("What is the sum of %d and %d? 🤔\n", num1, num2);
    int user_sum;
    scanf("%d", &user_sum);
    if (user_sum == sum) {
        printf("Yay! You got it right! 🎉\n");
    } else {
        printf("Oops! The correct answer is %d. Better luck next time! 😌\n", sum);
    }

    // Now, let's try a bit of multiplication:
    int num3 = 789;
    int num4 = 101;
    int product = num3 * num4;
    printf("What is the product of %d and %d? 🤔\n", num3, num4);
    int user_product;
    scanf("%d", &user_product);
    if (user_product == product) {
        printf("Amazing! You're a multiplication master! 🤩\n");
    } else {
        printf("Oh no! The correct answer is %d. Practice makes perfect! 🌈\n", product);
    }

    // How about some geometry? 📐
    float radius = 5.0;
    float area_of_circle = M_PI * radius * radius;
    printf("What is the area of a circle with a radius of %.1f? 🤔\n", radius);
    float user_area;
    scanf("%f", &user_area);
    if (fabs(user_area - area_of_circle) < 0.001) {
        printf("Fantastic! You're a geometry whiz! ✨\n");
    } else {
        printf("Hmmm... The correct answer is %.2f. Keep exploring and you'll get there! 🌍\n", area_of_circle);
    }

    // And finally, a little bit of statistics: 📊
    int data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(data) / sizeof(int);
    int min = data[0];
    int max = data[0];
    float avg = 0.0;
    for (int i = 0; i < size; i++) {
        if (data[i] < min) {
            min = data[i];
        }
        if (data[i] > max) {
            max = data[i];
        }
        avg += data[i];
    }
    avg /= size;
    printf("What is the minimum, maximum, and average of the following data set: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("? 🤔\n");
    int user_min, user_max;
    float user_avg;
    scanf("%d %d %f", &user_min, &user_max, &user_avg);
    if (user_min == min && user_max == max && fabs(user_avg - avg) < 0.001) {
        printf("Bravo! You're a data analysis extraordinaire! 🏆\n");
    } else {
        printf("Oops! The correct answers are: minimum = %d, maximum = %d, average = %.2f. Keep practicing and you'll be a pro! 💪\n", min, max, avg);
    }

    // Thank you for taking part in my fun math exercise program! 😊
    // Keep exploring and learning, and remember, math is all around us! 🌍
    return 0;
}