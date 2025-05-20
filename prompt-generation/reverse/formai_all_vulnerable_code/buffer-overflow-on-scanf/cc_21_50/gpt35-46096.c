//FormAI DATASET v1.0 Category: HTML beautifier ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLINE 1024 /* maximum length of input line */
#define TABSIZE 4   /* the default number of space character used for each tab character */

int main (int argc, char **argv)
{
    FILE *fpin, *fpout; /* input and output file pointer */
    char *progname = argv[0]; /* program name */
    char infile[MAXLINE], outfile[MAXLINE]; /* file names */
    char line[MAXLINE]; /* input line buffer */
    char *newline; /* the modified line buffer */
    int len, i, j, k, t;
    int tabsize = TABSIZE; /* number of space character used for each tab character */
    int changes = 0; /* the number of changes made */
    int lineno = 0; /* line number */
    int out_len = 0; /* length of output line */
    int tab_count = 0; /* number of tab characters */
    int space_count = 0; /* number of space characters that can replace a tab character */

    /* parse the command line options */
    i = 1;
    while (i < argc && argv [i][0] == '-') {
        for (j = 1; j < strlen (argv [i]); j ++) {
            switch (argv [i][j]) {
            case 't': /* set the number of space characters used for each tab character */
                if (i + 1 < argc) {
                    i ++;
                    tabsize = atoi (argv [i]);
                    if (tabsize <= 0) {
                        printf ("%s: invalid tab size '%s'\n", progname, argv [i]);
                        exit (1);
                    }
                } else {
                    printf ("%s: option '-t' requires an argument\n", progname);
                    exit (1);
                }
                break;
            default: /* unknown option */
                printf ("%s: unknown option '%s'\n", progname, argv [i]);
                exit (1);
                break;
            }
        }
        i ++;
    }

    /* read the input file name */
    if (i < argc) {
        strcpy (infile, argv [i]);
    } else {
        printf ("Input file:");
        scanf ("%s", infile);
    }
    /* open the input file */
    if ((fpin = fopen (infile, "r")) == NULL) {
        printf ("%s: cannot open input file '%s'\n", progname, infile);
        exit (1);
    }

    /* read the output file name */
    if (i + 1 < argc) {
        strcpy (outfile, argv [i + 1]);
    } else {
        printf ("Output file:");
        scanf ("%s", outfile);
    }
    /* open the output file */
    if ((fpout = fopen (outfile, "w")) == NULL) {
        printf ("%s: cannot open output file '%s'\n", progname, outfile);
        exit (1);
    }

    /* process the input file line by line */
    while (fgets (line, MAXLINE, fpin) != NULL) {
        len = strlen (line);
        lineno ++;
        if (len == MAXLINE - 1 && line[MAXLINE - 2] != '\n') {
            /* skip this line, since it is too long */
            printf ("%s: line %d too long\n", progname, lineno);
        } else {
            /* modify the line */
            newline = (char*) malloc ((len + 1) * sizeof (char));
            out_len = 0;
            tab_count = 0;
            space_count = 0;
            for (i = 0; i < len; i ++) {
                switch (line[i]) {
                case '\t': /* replace tab character */
                    space_count = tabsize - (out_len % tabsize);
                    for (j = 0; j < space_count; j ++) {
                        newline[out_len ++] = ' ';
                    }
                    tab_count ++;
                    break;
                case '\r': /* ignore carriage return character */
                    break;
                case '\n': /* newline character */
                    if (out_len != 0 && newline[out_len - 1] == ' ') {
                        newline[out_len - 1] = '\n';
                    } else {
                        newline[out_len ++] = '\n';
                    }
                    break;
                default: /* other characters */
                    newline[out_len ++] = line[i];
                    break;
                }
            }
            newline[out_len] = '\0';

            /* write the modified line to output file */
            fprintf (fpout, "%s", newline);

            changes ++;
            free (newline);
        }
    }

    /* close the input and output files */
    fclose (fpin);
    fclose (fpout);

    /* print the summary */
    printf ("%d lines processed, %d changes made\n", lineno, changes);

    return 0;
}