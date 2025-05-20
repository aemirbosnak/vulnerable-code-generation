//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Parsing error? Who's parsing error?
void syntax_error(char *msg) {
    fprintf(stderr, "Syntax error: %s\n", msg);
    exit(1);
}

// What's this? A program that thinks it's a parser?
int main(int argc, char **argv) {
    // Oh, you want to run this program?
    if (argc < 2) syntax_error("No input file!");
    
    // Hold on to your socks, we're about to open a file!
    FILE *fp = fopen(argv[1], "r");
    if (!fp) syntax_error("Failed to open file!");
    
    // Let's hope this file isn't too confusing...
    char *buf = malloc(1024);
    if (!buf) syntax_error("Failed to allocate memory!");
    
    // What's this? A while loop? But it's not even Christmas!
    while (fgets(buf, 1024, fp)) {
        // Hold your breath, we're about to parse a line!
        char *p = buf;
        
        // Oh no, it's a keyword! Run for your lives!
        if (*p == 'i' && !strcmp(p, "int")) {
            p += 3;
            
            // Don't blink, we're looking for a variable name!
            while (*p && *p != ';') p++;
            
            // Phew, made it through that one...
            if (!*p) syntax_error("Expected semicolon!");
            
            // Wait, what? We're not done yet?
            p++;
        }
        
        // Oh boy, a semicolon! The fun never ends!
        else if (*p == ';') {
            p++;
        }
        
        // What the heck is this? A function call? I thought this was a toy language!
        else if (*p == 'p' && !strcmp(p, "printf")) {
            p += 6;
            
            // Oh, just a string? That's easy!
            while (*p && *p != '\"') p++;
            
            // Oops, forgot about that pesky semicolon again...
            if (!*p || *++p != '\"') syntax_error("Expected closing quotation mark!");
            p++;
            
            // One more semicolon and we're done with this line!
            if (!*p || *++p != ';') syntax_error("Expected semicolon!");
            p++;
        }
        
        // Oh my heavens, a comment? What is this, a programming language or a novel?
        else if (*p == '/') {
            if (*++p == '/') {
                // A single-line comment? How quaint!
                while (*p && *p != '\n') p++;
            } else if (*p == '*') {
                // A multi-line comment? This is getting serious!
                while (*p && *p != '*' && *++p != '/') {}
                if (!*p) syntax_error("Unterminated multi-line comment!");
                p += 2;
            } else {
                // What in tarnation is this?
                syntax_error("Invalid comment!");
            }
        }
        
        // What's this? The end of the line? Oh thank goodness!
        else if (!*p) {
            // Nothing to see here, move along!
        }
        
        // Oops, I totally forgot about errors!
        else {
            syntax_error("Unexpected token!");
        }
    }
    
    // Whew, I think we made it through that nightmare!
    fclose(fp);
    free(buf);
    
    // Congratulations, you parsed a program! Now what?
    return 0;
}