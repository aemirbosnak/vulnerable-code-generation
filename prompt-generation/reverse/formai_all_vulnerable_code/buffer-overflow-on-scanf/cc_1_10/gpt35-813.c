//FormAI DATASET v1.0 Category: HTML beautifier ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void beautifyHTML(char *filename);

int main()
{
    char filename[100];

    printf("Enter the name of HTML file to beautify (with extension): ");
    scanf("%s", filename);

    beautifyHTML(filename);

    printf("Beautification complete!\n");

    return 0;
}

void beautifyHTML(char *filename)
{
    FILE *infile, *outfile;
    int indentSpaces = 0, prevIndent = 0, insideTag = 0, insideQuotes = 0, shouldIndent = 0;
    char line[1000], outfile_name[100];

    // Open file
    infile = fopen(filename, "r");
    if (infile == NULL) {
        printf("Cannot open file: %s.\n", filename);
        exit(1);
    }

    // Create output file name
    sprintf(outfile_name, "beautified_%s", filename);
    outfile = fopen(outfile_name, "w");

    // Process file
    while (fgets(line, sizeof(line), infile)) {
        int i;

        // Check for opening/closing of tag
        for (i = 0; line[i] != '\n'; i++) {

            if (line[i] == '"') {
                if (insideQuotes) {
                    insideQuotes = 0;
                } else {
                    insideQuotes = 1;
                }
            }

            if (!insideQuotes) {
                if (line[i] == '<') {
                    if (shouldIndent) {
                        indentSpaces += 4;
                        shouldIndent = 0;
                    }
                    insideTag = 1;
                } else if (line[i] == '>') {
                    insideTag = 0;
                    fprintf(outfile, ">\n");
                    shouldIndent = 1;
                }
            }
        }

        // Indent appropriately
        if (prevIndent != indentSpaces) {
            prevIndent = indentSpaces;
            fprintf(outfile, "\n");
            for (i = 0; i < indentSpaces; i++) {
                fprintf(outfile, " ");
            }
        }

        // Output line
        for (i = 0; line[i] != '\n'; i++) {
            fprintf(outfile, "%c", line[i]);
        }
        fprintf(outfile, "\n");
    }

    // Close files
    fclose(infile);
    fclose(outfile);
}