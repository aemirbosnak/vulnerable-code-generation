//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BOLD(x) "\033[1m"x"\033[0m"
#define UNDERLINE(x) "\033[4m"x"\033[0m"
#define REVERSE(x) "\033[7m"x"\033[0m"

int main()
{
    char color[20];
    int i, r, g, b;
    int valid = 0;
    printf("Enter a color name or hex code: ");
    scanf("%s", color);

    // Check if the input is a hex code
    if (color[0] == '#')
    {
        if (strlen(color) == 7)
        {
            for (i = 1; i < strlen(color); i++)
            {
                if (!isxdigit(color[i]))
                {
                    printf("Invalid hex code.\n");
                    return 1;
                }
            }
            sscanf(color, "#%02x%02x%02x", &r, &g, &b);
            valid = 1;
        }
    }
    else
    {
        // Check if the input is a valid color name
        for (i = 0; i < strlen(color); i++)
        {
            if (!isalpha(color[i]) && !isspace(color[i]))
            {
                printf("Invalid color name.\n");
                return 1;
            }
        }
        r = g = b = 0;
        if (strcmp(color, "red") == 0)
        {
            r = 255;
        }
        else if (strcmp(color, "green") == 0)
        {
            g = 255;
        }
        else if (strcmp(color, "blue") == 0)
        {
            b = 255;
        }
        else if (strcmp(color, "yellow") == 0)
        {
            r = 255;
            g = 255;
        }
        else if (strcmp(color, "magenta") == 0)
        {
            r = 255;
            b = 255;
        }
        else if (strcmp(color, "cyan") == 0)
        {
            g = 255;
            b = 255;
        }
        else if (strcmp(color, "white") == 0)
        {
            r = g = b = 255;
        }
        else if (strcmp(color, "black") == 0)
        {
            r = g = b = 0;
        }
        else
        {
            printf("Invalid color name.\n");
            return 1;
        }
        valid = 1;
    }

    if (valid)
    {
        // Print the color code in hex and RGB formats
        printf("Hex code: #%02x%02x%02x\n", r, g, b);
        printf("RGB code: (%d, %d, %d)\n", r, g, b);
    }

    return 0;
}