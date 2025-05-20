//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: puzzling
#include <stdio.h>
#include <string.h>

// A tricky way to define a macro that expands to a string
#define M(s) #s

// An array of strings representing HTML tags
char *tags[] = {
    M(<h1>), M(<h2>), M(<h3>), M(<h4>), M(<h5>), M(<h6>),
    M(</h1>), M(</h2>), M(</h3>), M(</h4>), M(</h3>), M(</h6>),
    M(<a>), M(</a>), M(<p>), M(</p>), M(<br>),
    M(<ul>), M(</ul>), M(<li>), M(</li>),
    M(<ol>), M(</ol>), M(<dl>), M(</dl>), M(<dt>), M(</dt>),
    M(<dd>), M(</dd>), M(<table>), M(</table>), M(<tr>), M(</tr>),
    M(<td>), M(</td>), M(<form>), M(</form>), M(<input>),
    M(</input>), M(<textarea>), M(</textarea>), M(<select>),
    M(</select>), M(<option>), M(</option>), M(<button>),
    M(</button>), M(<iframe>), M(</iframe>), M(<embed>),
    M(</embed>), M(<object>), M(</object>), M(<param>),
    M(</param>), M(<video>), M(</video>), M(<audio>), M(</audio>),
    M(<canvas>), M(</canvas>), M(<svg>), M(</svg>), M(<math>),
    M(</math>), M(<foreignObject>), M(</foreignObject>),
    M(<desc>), M(</desc>), M(<title>), M(</title>),
    M(<style>), M(</style>), M(<script>), M(</script>),
    M(<!--), M(-->), M(<meta>), M(</meta>),
    M(<link>), M(</link>), M(<base>), M(</base>),
    M(<head>), M(</head>), M(<body>), M(</body>),
    M(<!DOCTYPE html>)
};

// A function to beautify a string of HTML code
char *beautify_html(char *html) {
    // Allocate memory for the beautified HTML code
    char *beautified_html = malloc(strlen(html) * 2);

    // Initialize the beautified HTML code
    strcpy(beautified_html, "");

    // Iterate over the characters in the HTML code
    for (int i = 0; i < strlen(html); i++) {
        // If the current character is a '<' character, then check if it is the start
        // of a tag
        if (html[i] == '<') {
            // If the next character is a '/' character, then it is the end of a tag
            if (html[i + 1] == '/') {
                // Find the matching start tag
                for (int j = 0; j < strlen(html); j++) {
                    if (strncmp(&html[j], &html[i], strlen(&html[i])) == 0) {
                        // Copy the end tag to the beautified HTML code
                        strcat(beautified_html, &html[i]);

                        // Break the loop
                        break;
                    }
                }
            } else {
                // Find the matching end tag
                for (int j = 0; j < strlen(html); j++) {
                    if (strncmp(&html[j], &html[i], strlen(&html[i])) == 0) {
                        // Copy the start tag to the beautified HTML code
                        strcat(beautified_html, &html[i]);

                        // Break the loop
                        break;
                    }
                }
            }
        } else {
            // Copy the current character to the beautified HTML code
            strncat(beautified_html, &html[i], 1);
        }
    }

    // Return the beautified HTML code
    return beautified_html;
}

// A function to print a string of HTML code in a visually appealing way
void print_html(char *html) {
    // Iterate over the lines of the HTML code
    for (int i = 0; i < strlen(html); i++) {
        // If the current line is a start tag, then print it in a different color
        if (html[i] == '<') {
            printf("\x1b[32m");
        }

        // Print the current line
        printf("%c", html[i]);

        // If the current line is an end tag, then print it in a different color
        if (html[i] == '>') {
            printf("\x1b[0m");
        }
    }

    // Print a newline character
    printf("\n");
}

// The main function
int main() {
    // Get the HTML code from the user
    char *html = malloc(1024);
    printf("Enter the HTML code: ");
    gets(html);

    // Beautify the HTML code
    char *beautified_html = beautify_html(html);

    // Print the beautified HTML code
    printf("Beautified HTML code:\n");
    print_html(beautified_html);

    // Free the memory allocated for the beautified HTML code
    free(beautified_html);

    // Free the memory allocated for the HTML code
    free(html);

    // Return 0
    return 0;
}