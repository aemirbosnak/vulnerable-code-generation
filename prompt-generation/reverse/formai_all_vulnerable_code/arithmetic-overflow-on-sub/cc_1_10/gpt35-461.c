//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void pause(int milliseconds) {
    clock_t start_time = clock();

    while ((clock() - start_time) < milliseconds);
}

int main() {
    printf("Welcome to the Time Travel Simulator!\n");

    printf("\nYou find yourself transported to the year 1890 in the heart of London. You look around and see bustling city streets filled with horse-drawn carriages and gas lamps lining the sidewalks.\n\n");

    pause(2000);

    printf("You hear a commotion down the street, and decide to investigate.\n\n");

    pause(2000);

    printf("As you arrive at the scene, you see a group of people surrounding a body lying on the ground. Without hesitation, you push your way through the crowd and kneel down to examine the deceased.\n\n");

    pause(2000);

    printf("The dead man is dressed in the attire of an aristocrat, and you notice a small calling card in his pocket. Upon further inspection, you see that it is a calling card for none other than Sherlock Holmes!\n\n");

    pause(2000);

    printf("You decide to take on the investigation and look further into the matter.\n\n");

    pause(2000);

    printf("You make your way back to Baker Street where you meet with Sherlock Holmes. He tells you that there have been a series of similar murders happening around London, and he suspects a notorious serial killer is on the loose.\n\n");

    pause(2000);

    printf("Sherlock Holmes has a hunch on who the killer could be, and instructs you to use the Time Travel Simulator to travel to different points in time to gather evidence and solve the case.\n\n");

    pause(2000);

    printf("You sit at the control panel of the Time Travel Simulator and enter in the coordinates for the year 1895, the year in which the killer is believed to have committed his first murder.\n\n");

    pause(2000);

    int year = 1895;

    printf("The year is now %d. You look around and see a bustling London street filled with people going about their daily business. You spot a man loitering near a dark alley, and upon closer inspection, you realize that it is the serial killer himself!\n\n", year);

    pause(2000);

    printf("You follow the killer into the alleyway, keeping a safe distance so as not to be spotted. After a few minutes, he approaches a woman walking down the street and stabs her before making a quick exit.\n\n");

    pause(2000);

    printf("You take note of the killer's appearance and clothing, and quickly return to the Time Travel Simulator to report your findings to Sherlock Holmes.\n\n");

    pause(2000);

    printf("You enter in the coordinates for the year 1898, where the next murder is believed to have taken place.\n\n");

    pause(2000);

    year = 1898;

    printf("The year is now %d. You find yourself in a quiet London neighborhood, and after asking around, you find the location of the murder.\n\n", year);

    pause(2000);

    printf("You examine the crime scene and manage to find some crucial evidence, a torn piece of clothing that matches the description of the killer's attire.\n\n");

    pause(2000);

    printf("You return to the Time Travel Simulator with the evidence, and set the coordinates for the year 1900. You know that this is the year that the killer will strike again.\n\n");

    pause(2000);

    year = 1900;

    printf("The year is now %d. You make your way to the location where the murder is going to happen but are horrified to realize that you are too late. The killer has already struck and is nowhere to be found.\n\n", year);

    pause(2000);

    printf("You scour the area for clues until you finally find some important evidence that will help you to identify the killer.\n\n");

    pause(2000);

    printf("You return to the Time Travel Simulator and transport yourself back to the present day. You meet with Sherlock Holmes and present him with the evidence. Together, you are able to identify the killer and bring him to justice. Congratulations, you have solved the case!\n");

    return 0;
}