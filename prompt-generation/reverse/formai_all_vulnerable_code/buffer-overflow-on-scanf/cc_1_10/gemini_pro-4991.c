//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: inquisitive
#include <stdio.h>
#include <math.h>

int main() {
    // Welcome message
    printf("Welcome to the Math Exercise Program!\n");
    printf("We're going to explore some interesting mathematical concepts together.\n\n");

    // Exercise 1: Calculate the area of a circle
    printf("**Exercise 1: Area of a Circle**\n");
    printf("Imagine you have a beautiful circular garden with a radius of 5 meters.\n");
    printf("What is the area of your garden, in square meters?\n");
    printf("Hint: The formula for the area of a circle is A = πr², where π is a mathematical constant approximately equal to 3.14.\n");
    printf("Enter your answer below (rounded to the nearest integer): ");
    int answer1;
    scanf("%d", &answer1);

    // Check the answer
    int correctAnswer1 = (int)round(M_PI * 5 * 5);
    if (answer1 == correctAnswer1) {
        printf("Congratulations! You got it right.\n\n");
    } else {
        printf("Oops, that's not quite correct. The correct answer is %d square meters.\n\n", correctAnswer1);
    }

    // Exercise 2: Find the volume of a cube
    printf("**Exercise 2: Volume of a Cube**\n");
    printf("Now, imagine you have a cube-shaped gift box with sides measuring 10 centimeters.\n");
    printf("What is the volume of the gift box, in cubic centimeters?\n");
    printf("Hint: The formula for the volume of a cube is V = s³, where s is the length of one side.\n");
    printf("Enter your answer below (rounded to the nearest integer): ");
    int answer2;
    scanf("%d", &answer2);

    // Check the answer
    int correctAnswer2 = 10 * 10 * 10;
    if (answer2 == correctAnswer2) {
        printf("Fantastic! You nailed it.\n\n");
    } else {
        printf("Oh, it seems you missed the mark. The correct answer is %d cubic centimeters.\n\n", correctAnswer2);
    }

    // Exercise 3: Solve a linear equation
    printf("**Exercise 3: Solving a Linear Equation**\n");
    printf("Let's play detective and solve a simple equation:\n");
    printf("2x + 5 = 13\n");
    printf("What is the value of x?\n");
    printf("Hint: Isolate the variable by performing inverse operations.\n");
    printf("Enter your answer below (rounded to the nearest integer): ");
    int answer3;
    scanf("%d", &answer3);

    // Check the answer
    int correctAnswer3 = 4;
    if (answer3 == correctAnswer3) {
        printf("Bravo! You cracked the code.\n\n");
    } else {
        printf("Hmm, not quite there yet. The correct answer is %d.\n\n", correctAnswer3);
    }

    // Exercise 4: Calculate the hypotenuse of a right triangle
    printf("**Exercise 4: Hypotenuse of a Right Triangle**\n");
    printf("Imagine you have a rectangular piece of paper folded diagonally, forming a right triangle.\n");
    printf("The shorter side of the triangle is 6 centimeters, and the longer side is 8 centimeters.\n");
    printf("What is the length of the hypotenuse, the longest side of the triangle?\n");
    printf("Hint: Use the Pythagorean theorem: a² + b² = c², where a and b are the lengths of the shorter sides, and c is the length of the hypotenuse.\n");
    printf("Enter your answer below (rounded to the nearest integer): ");
    int answer4;
    scanf("%d", &answer4);

    // Check the answer
    int correctAnswer4 = (int)round(sqrt(6 * 6 + 8 * 8));
    if (answer4 == correctAnswer4) {
        printf("Impressive! You're a geometry whiz.\n\n");
    } else {
        printf("Hmm, seems like you're a bit off. The correct answer is %d centimeters.\n\n", correctAnswer4);
    }

    // Exercise 5: Find the average of a set of numbers
    printf("**Exercise 5: Average of a Set of Numbers**\n");
    printf("Let's say you have a collection of test scores: 90, 85, 95, and 75.\n");
    printf("What is the average score?\n");
    printf("Hint: Add up all the scores and divide by the number of scores.\n");
    printf("Enter your answer below (rounded to the nearest integer): ");
    int answer5;
    scanf("%d", &answer5);

    // Check the answer
    int correctAnswer5 = (90 + 85 + 95 + 75) / 4;
    if (answer5 == correctAnswer5) {
        printf("Well done! You got it.\n\n");
    } else {
        printf("Oops, that's not quite right. The correct answer is %d.\n\n", correctAnswer5);
    }

    // Thank you message
    printf("Thank you for completing the Math Exercise Program!\n");
    printf("We hope you had fun and learned something new along the way.\n");

    return 0;
}