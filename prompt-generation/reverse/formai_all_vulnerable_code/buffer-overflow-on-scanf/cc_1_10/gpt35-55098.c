//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: complete
#include <stdio.h>
#include <string.h>

int main()
{
    // Define the character map we'll use to generate ASCII art
    char character_map[26][10] = {
        "   # # # \n  #     #\n#       #\n#       #\n#       #\n  #   # \n   ###",
        "   ####  \n  #    # \n      #  \n     #   \n   #     \n ##      \n######",
        "   ##### \n  #     #\n      ## \n   ##### \n ##      \n#        \n########",
        "  ###### \n #      #\n      ## \n  ###### \n      ## \n #      #\n####### ",
        "  ##   ##\n  # # # \n   ###  \n   ###  \n  #   # \n #     #\n#       #",
        "##      \n# #     \n#  #    \n#   #   \n#  #    \n# #     \n##      ",
        "  ###### \n #      #\n#        \n#  ######\n#      # \n#      # \n#######  ",
        "########\n      # \n     #  \n    #   \n   #    \n  #     \n #      ",
        "   #   # \n   #  #  \n   # #   \n   # #   \n   #  #  \n   #   # \n   #   # ",
        "        #\n         \n  #    # \n     #   \n    #    \n         \n        #",
        "      # #\n     #   \n    #    \n    #    \n     #   \n      # #\n        #",
        "          \n     #   \n     #   \n     #   \n     #   \n          \n          ",
        "      #  \n      #  \n      #  \n      #  \n      #  \n      #  \n#######  ",
        "   #    #\n   ##  ##\n  # # # #\n #  #   #\n#       #\n#       #\n#       #",
        " ####### \n      # \n      # \n      # \n      # \n      # \n ####### ",
        "   ##### \n ##     #\n#        \n#        \n#        \n ##     #\n   ##### ",
        " ####### \n      # \n      # \n ####### \n      # \n      # \n ####### ",
        " ####### \n      # \n      # \n ####### \n      # \n      # \n      # ",
        "   ##### \n ##     #\n#        \n#   #### \n#      # \n ##    # \n   ####  ",
        " #       \n #       \n #       \n #       \n #       \n #       \n#######  ",
        "#       #\n #     # \n  #   #  \n   # #   \n    #    \n         \n    #    ",
        "#        \n #       \n  #      \n   #     \n    #    \n     #   \n      #  ",
        " #     # \n  #   #  \n   # #   \n    #    \n   # #   \n  #   #  \n #     # ",
        " #     # \n  #   #  \n   # #   \n    #    \n    #    \n    #    \n    #    "};

    // Ask the user to input text to be converted to ASCII art
    char user_text[50];
    printf("Enter text to convert to ASCII art:\n");
    scanf("%s",user_text);
    
    // Loop through each character in the user's input
    for(int i = 0; i < strlen(user_text); i++) {
        // Convert the current character to uppercase and get its ASCII value
        int current_char = toupper(user_text[i]);
        int ascii_value = current_char - 65;
        
        // If it's a space, print a blank line
        if(current_char == 32) {
            printf("\n\n\n");
        }
        // If it's not a space, print the ASCII art for the character
        else {
            printf("%s   ", character_map[ascii_value]);
        }
    }
    
    return 0;
}