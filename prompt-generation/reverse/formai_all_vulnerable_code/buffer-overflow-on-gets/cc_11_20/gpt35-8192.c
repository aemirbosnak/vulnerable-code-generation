//FormAI DATASET v1.0 Category: Smart home automation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[50]; // to store voice commands
    int lights = 0; // 0 = off, 1 = on
    int air = 0; // 0 = off, 1 = on
    int security = 0; // 0 = off, 1 = on

    printf("Welcome to your Smart Home! We strive to make your life happier and easier.\n");
    printf("To control the lights say 'Turn on/off the lights'\n");
    printf("To control the air conditioning say 'Turn on/off the air conditioning'\n");
    printf("To control the security system say 'Turn on/off the security system'\n");
    printf("To exit say 'Goodbye'\n");

    while(1) // infinite loop to wait for voice commands
    {
        printf("What would you like to do? ");
        gets(input);

        if(strcasecmp(input, "Turn on the lights") == 0) // turn on lights
        {
            if(lights == 0)
            {
                lights = 1;
                printf("Turning on the lights.\n");
                system("mpg321 cheerful_jingle.mp3 &"); // play cheerful jingle
            }
            else
            {
                printf("The lights are already on.\n");
            }
        }
        else if(strcasecmp(input, "Turn off the lights") == 0) // turn off lights
        {
            if(lights == 1)
            {
                lights = 0;
                printf("Turning off the lights.\n");
                system("mpg321 cheerful_jingle.mp3 &"); // play cheerful jingle
            }
            else
            {
                printf("The lights are already off.\n");
            }
        }
        else if(strcasecmp(input, "Turn on the air conditioning") == 0) // turn on air
        {
            if(air == 0)
            {
                air = 1;
                printf("Turning on the air conditioning.\n");
                system("mpg321 cheerful_jingle.mp3 &"); // play cheerful jingle
            }
            else
            {
                printf("The air conditioning is already on.\n");
            }
        }
        else if(strcasecmp(input, "Turn off the air conditioning") == 0) // turn off air
        {
            if(air == 1)
            {
                air = 0;
                printf("Turning off the air conditioning.\n");
                system("mpg321 cheerful_jingle.mp3 &"); // play cheerful jingle
            }
            else
            {
                printf("The air conditioning is already off.\n");
            }
        }
        else if(strcasecmp(input, "Turn on the security system") == 0) // turn on security
        {
            if(security == 0)
            {
                security = 1;
                printf("Turning on the security system.\n");
                system("mpg321 cheerful_jingle.mp3 &"); // play cheerful jingle
            }
            else
            {
                printf("The security system is already on.\n");
            }
        }
        else if(strcasecmp(input, "Turn off the security system") == 0) // turn off security
        {
            if(security == 1)
            {
                security = 0;
                printf("Turning off the security system.\n");
                system("mpg321 cheerful_jingle.mp3 &"); // play cheerful jingle
            }
            else
            {
                printf("The security system is already off.\n");
            }
        }
        else if(strcasecmp(input, "Goodbye") == 0) // exit program
        {
            printf("Goodbye! Have a cheerful day!\n");
            break;
        }
        else // voice command not recognized
        {
            printf("I'm sorry, I didn't understand that command. Please try again.\n");
        }
    }

    return 0;
}