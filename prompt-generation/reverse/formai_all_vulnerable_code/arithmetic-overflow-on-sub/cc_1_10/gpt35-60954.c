//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main()
{
    //Set up variables
    char user_input;
    int letter_count = 0;
    int incorrect_count = 0;
    int correct_count = 0;
    double elapsed_time;
    clock_t start_time, end_time;
    
    //Prompt user to start the test
    printf("Welcome to the typing speed test! Press ENTER to begin.\n");
    scanf("%c", &user_input);
    
    //Generate a random paragraph for user to type
    srand(time(0));
    const char *paragraphs[10] = {
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam eget nibh justo. Cras odio augue, semper nec accumsan nec, molestie at massa. Integer volutpat urna sed nulla posuere tempor. Fusce vitae justo feugiat, mattis elit id, efficitur nibh. Cras vehicula purus quis ipsum efficitur efficitur.",
        "Fusce semper, mi congue feugiat cursus, ligula eros eleifend orci, eget iaculis est nulla vel odio. Maecenas eu purus luctus, tincidunt ante at, congue justo. Morbi aliquet ligula vitae sapien tempus, in pulvinar odio ultrices.",
        "Sed eu consequat sapien. Aenean eget risus sit amet nunc gravida fringilla. Vivamus id turpis et orci consequat mollis a at odio. Ut vel purus at velit dictum mollis. Vestibulum sodales magna vitae urna rutrum volutpat.",
        "Mauris euismod eget felis at pretium. Fusce euismod nisi vitae magna commodo fermentum. Integer mattis tincidunt risus eu dignissim. Nullam id ante ut risus feugiat facilisis ac eu mauris. Etiam aliquam sem in libero imperdiet ullamcorper.",
        "Nullam vel elit vitae magna dignissim efficitur. Suspendisse eros sem, tincidunt eu imperdiet nec, vestibulum eget erat. Sed euismod pharetra sem, quis gravida velit cursus ac. Proin imperdiet sit amet arcu a molestie. Praesent porta, mauris in consequat tempus, eros sapien semper enim, sit amet vestibulum massa odio quis nibh.",
        "Phasellus eu magna a velit bibendum fermentum vel id velit. Proin rutrum quam in nunc vestibulum, ut elementum risus cursus. Nam laoreet quam sem, vel gravida quam posuere a. Morbi malesuada nisl ut massa tincidunt, sit amet condimentum lorem rhoncus. Nam faucibus purus a cursus mattis.",
        "Cras interdum velit eu nibh porta tristique. Aliquam aliquet luctus sapien, eget vestibulum neque pretium vitae. Sed aliquet, nunc vel luctus facilisis, ante mi porttitor justo, sed sodales erat dui eu eros. Donec sem justo, accumsan vel lacus eu, molestie elementum libero.",
        "Pellentesque vitae magna nec mi feugiat fringilla. Nam consectetur nulla nec ipsum fringilla, eget consequat metus ultricies. Sed lobortis vestibulum feugiat. Morbi venenatis maximus mi, vitae venenatis odio sodales vel. Sed varius leo felis, ut dapibus felis efficitur in.",
        "Donec sed leo vel velit fringilla ullamcorper. Ut magna turpis, euismod et viverra vitae, mattis id velit. Nullam tristique mauris vel mattis aliquam. Sed commodo volutpat sapien, vel ullamcorper felis lacinia eget. Mauris elit felis, consequat ac justo at, feugiat bibendum velit.",
        "Fusce tincidunt pretium blandit. Aenean at auctor mauris, a semper velit. Integer lacinia lacus neque, vel maximus tortor luctus a. Vestibulum in leo id orci pharetra suscipit. Duis mi nisi, laoreet eu leo quis, maximus accumsan elit."
    };
    int random_index = rand() % 10;
    const char *paragraph = paragraphs[random_index];
    
    //Display paragraph to user
    printf("\n%s\n", paragraph);
    
    //Start timer
    start_time = clock();
    
    //Loop through paragraph and get user input
    while (*paragraph)
    {
        user_input = getchar();
        if (user_input == *paragraph)
        {
            correct_count++;
            letter_count++;
        }
        else if (user_input == '\n' || user_input == '\r')
        {
            continue;
        }
        else
        {
            incorrect_count++;
            letter_count++;
        }
        paragraph++;
    }
    
    //Stop timer and calculate elapsed time
    end_time = clock();
    elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;
    
    //Display results
    printf("\nYou typed %d letters in %.2f seconds.\n", letter_count, elapsed_time);
    printf("You had %d incorrect letters and %d correct letters.\n", incorrect_count, correct_count);
    printf("Your typing speed is %.2f letters per second.\n", (double) letter_count / elapsed_time);
    
    return 0;
}