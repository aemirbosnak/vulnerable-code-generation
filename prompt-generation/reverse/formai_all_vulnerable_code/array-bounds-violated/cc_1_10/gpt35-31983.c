//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 100 // maximum size of each line read from the input file

typedef struct {
    char name[MAX_LINE_SIZE];
    char email[MAX_LINE_SIZE];
    char phone[MAX_LINE_SIZE];
    char address[MAX_LINE_SIZE];
    char education[MAX_LINE_SIZE];
    char experience[MAX_LINE_SIZE];
} Resume;

typedef struct {
    char name[MAX_LINE_SIZE];
    char email[MAX_LINE_SIZE];
    char phone[MAX_LINE_SIZE];
    char address[MAX_LINE_SIZE];
    char education[MAX_LINE_SIZE];
    char experience[MAX_LINE_SIZE];
    int match_score;
} MatchingResume;

void parse_resume(Resume *resume, char *filename);
void parse_matching_resumes(MatchingResume *matching_resumes, char *filename, Resume *target_resume);
int count_lines(char *filename);
int compute_match_score(Resume *resume1, Resume *resume2);
void sort_matching_resumes(MatchingResume *matching_resumes, int num_resumes);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <resume_file> <matching_resumes_file>\n", argv[0]);
        return 1;
    }
    
    Resume target_resume;
    parse_resume(&target_resume, argv[1]); // parse the target resume
    
    int num_resumes = count_lines(argv[2]);
    MatchingResume *matching_resumes = malloc(sizeof(MatchingResume) * num_resumes);
    parse_matching_resumes(matching_resumes, argv[2], &target_resume); // parse the matching resumes and calculate their match scores
    
    sort_matching_resumes(matching_resumes, num_resumes); // sort the matching resumes by descending match score
    
    printf("Matching resumes sorted by match score:\n");
    printf("%-30s %-30s %-30s %-30s %-30s %-30s %-20s\n", "Name", "Email", "Phone", "Address", "Education", "Experience", "Match Score");
    for (int i = 0; i < num_resumes; i++) {
        printf("%-30s %-30s %-30s %-30s %-30s %-30s %-20d\n", matching_resumes[i].name, matching_resumes[i].email, matching_resumes[i].phone, matching_resumes[i].address, matching_resumes[i].education, matching_resumes[i].experience, matching_resumes[i].match_score);
    }
    
    free(matching_resumes);
    return 0;
}

void parse_resume(Resume *resume, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    
    char line[MAX_LINE_SIZE];
    int line_num = 0;
    while (fgets(line, sizeof(line), fp)) {
        line[strlen(line) - 1] = '\0'; // remove trailing newline character
        switch (line_num) {
            case 0:
                strcpy(resume->name, line);
                break;
            case 1:
                strcpy(resume->email, line);
                break;
            case 2:
                strcpy(resume->phone, line);
                break;
            case 3:
                strcpy(resume->address, line);
                break;
            case 4:
                strcpy(resume->education, line);
                break;
            case 5:
                strcpy(resume->experience, line);
                break;
        }
        line_num++;
    }
    
    fclose(fp);
}

void parse_matching_resumes(MatchingResume *matching_resumes, char *filename, Resume *target_resume) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    
    char line[MAX_LINE_SIZE];
    int line_num = 0;
    int resume_num = 0;
    while (fgets(line, sizeof(line), fp)) {
        line[strlen(line) - 1] = '\0'; // remove trailing newline character
        switch (line_num) {
            case 0:
                strcpy(matching_resumes[resume_num].name, line);
                break;
            case 1:
                strcpy(matching_resumes[resume_num].email, line);
                break;
            case 2:
                strcpy(matching_resumes[resume_num].phone, line);
                break;
            case 3:
                strcpy(matching_resumes[resume_num].address, line);
                break;
            case 4:
                strcpy(matching_resumes[resume_num].education, line);
                break;
            case 5:
                strcpy(matching_resumes[resume_num].experience, line);
                
                // compute match score between target resume and the current matching resume
                Resume current_resume;
                strcpy(current_resume.name, matching_resumes[resume_num].name);
                strcpy(current_resume.email, matching_resumes[resume_num].email);
                strcpy(current_resume.phone, matching_resumes[resume_num].phone);
                strcpy(current_resume.address, matching_resumes[resume_num].address);
                strcpy(current_resume.education, matching_resumes[resume_num].education);
                strcpy(current_resume.experience, matching_resumes[resume_num].experience);
                matching_resumes[resume_num].match_score = compute_match_score(target_resume, &current_resume);
                
                resume_num++;
                break;
        }
        line_num = (line_num + 1) % 6;
    }
    
    fclose(fp);
}

int count_lines(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    
    int num_lines = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            num_lines++;
        }
    }
    rewind(fp);
    
    fclose(fp);
    return num_lines / 6; // divide by 6 because each resume has 6 lines
}

int compute_match_score(Resume *resume1, Resume *resume2) {
    int match_score = 0;
    
    if (strcmp(resume1->name, resume2->name) == 0) {
        match_score++;
    }
    if (strcmp(resume1->email, resume2->email) == 0) {
        match_score++;
    }
    if (strcmp(resume1->phone, resume2->phone) == 0) {
        match_score++;
    }
    if (strcmp(resume1->address, resume2->address) == 0) {
        match_score++;
    }
    if (strcmp(resume1->education, resume2->education) == 0) {
        match_score++;
    }
    if (strcmp(resume1->experience, resume2->experience) == 0) {
        match_score++;
    }
    
    return match_score;
}

void sort_matching_resumes(MatchingResume *matching_resumes, int num_resumes) {
    for (int i = 0; i < num_resumes - 1; i++) {
        for (int j = i + 1; j < num_resumes; j++) {
            if (matching_resumes[i].match_score < matching_resumes[j].match_score) {
                MatchingResume temp = matching_resumes[i];
                matching_resumes[i] = matching_resumes[j];
                matching_resumes[j] = temp;
            }
        }
    }
}