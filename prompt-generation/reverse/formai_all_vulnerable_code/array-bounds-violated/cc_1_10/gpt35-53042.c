//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Romeo and Juliet
/* Romeo's C HTML Beautifier */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char html[1000], beautified_html[1000];
    int i, j = 0, tab_count = 0;

    printf("Oh holy code! Thy beauty enshrines me;\n");
    printf("Yet, I see thee disordered – a sight so heinous to my eyes!\n");
    printf("Pray, hand thy code, and I promise to make it shine suave like a dove.\n");
    printf("Go on, dear coder, give thy code, and witness my love!\n");

    fgets(html, sizeof(html), stdin);

    for (i = 0; html[i] != '\0'; i++)
    {
        if (html[i] == '<')
        {
            beautified_html[j] = '\n';
            for(int k = 0; k < tab_count; k++) {
                beautified_html[j+1+k] = '\t';
            }
            j+=tab_count+1;
            tab_count++;
            beautified_html[j++] = '<';
        }
        else if (html[i] == '>')
        {
            beautified_html[j++] = '>';
            beautified_html[j++] = '\n';
            tab_count--;
            for(int k = 0; k < tab_count; k++) {
                beautified_html[j+k] = '\t';
            }
            j+=tab_count;
        }
        else
        {
            beautified_html[j++] = html[i];
        }
    }
    beautified_html[j] = '\0';

    printf("\nAh, thy code, how perfectly refined!\n");
    printf("My heart sings with pleasure – that I, a mere lover of code, have brought thee eternal beauty!\n");
    printf("Be free, thy code, and live forever in pure opulence!\n");
    printf("Farewell, coding spirit – may we meet again sometime soon.\n");

    return 0;
}